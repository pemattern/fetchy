#include "fetchy.h"
#include "color.h"
#include "ascii.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <filesystem>

#include <unistd.h>
#include <sys/utsname.h>

namespace fetchy {
Fetchy::Fetchy() { Output(); }

std::string Fetchy::GetDistro() {
  char delimiter = '"';
  std::ifstream file("/etc/os-release");
  std::string line;
  std::regex regex("^NAME=\"(.*?)\"$");
  std::smatch match;
  std::string name;

  while (std::getline(file, line)) {
    if (std::regex_search(line, match, regex)) {
      name = BetweenDelimiter(match[0].str(), delimiter);
      break;
    }
  }
  return name;
}

std::string Fetchy::GetArchitechture() {
  struct utsname os_info {};
  uname(&os_info);
  return os_info.machine;
}

std::string Fetchy::GetDeviceName() {
  std::ifstream file("/sys/devices/virtual/dmi/id/product_version");
  std::string name;
  std::getline(file, name);
  return name;
}

std::string Fetchy::GetCPU() {
  std::ifstream file("/proc/cpuinfo");
  std::string line;

  while(std::getline(file, line)) {
    if (line.find("model name") != std::string::npos) {
      std::string name = line;

      size_t pos = name.find(": ");
      if (pos != std::string::npos)
        name = name.erase(0, pos + 2);

      pos = name.find_last_of(")");
      if (pos != std::string::npos)
        name = name.erase(0, pos + 2);

      pos = name.find("CPU");
      if (pos != std::string::npos)
        name = name.erase(pos, 4);
      
      return name;
    }
  }
  return "No CPU Found";
}

std::string Fetchy::GetGPU() {
    std::string name = "";
    const char* nvidia_query = "nvidia-smi --query-gpu=name --format=csv,noheader,nounits --id=0";
    const char* amd_query = "lspci| grep VGA | grep AMD";
    const char* intel_query = "lspci | grep VGA | grep 'Intel Corporation'";

    auto gpu_name = [](const char *query, std::string *name) {
      std::string result = "";
      FILE* pipe = popen(query, "r");

      char buffer[128];

      while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
      }

      pclose(pipe);

      if (!result.empty() && result.back() == '\n') {
        result.pop_back();
      }

      if (!result.empty()) {
        int colon_pos = result.find_last_of(':');
        if (colon_pos != std::string::npos) result = result.erase(0, colon_pos + 2);

        int paren_pos = result.find_last_of('(');
        if (paren_pos != std::string::npos) result = result.erase(paren_pos, result.length());
      }

      *name = result;
    };

    // NVIDIA
    gpu_name(nvidia_query, &name);
    if (!name.empty()) return name;

    // AMD
    gpu_name(amd_query, &name);
    if (!name.empty()) return name;

    // Intel Integrated
    gpu_name(intel_query, &name);
    if (!name.empty()) return name;

    return "No GPU Found";
}

std::string Fetchy::GetMemory() {
  long pages = sysconf(_SC_PHYS_PAGES);
  long page_size = sysconf(_SC_PAGE_SIZE);
  long free = sysconf(_SC_AVPHYS_PAGES);
  unsigned long long int total_memory = pages * page_size;
  unsigned long long int free_memory = free * page_size;
  int total_memory_gb = total_memory / (1024 * 1024 * 1024);
  int total_used_memory_gb = (total_memory - free_memory) / (1024 * 1024 * 1024);
  return std::to_string(total_used_memory_gb) + " / " + std::to_string(total_memory_gb + 1) + "GB";
}

std::string Fetchy::GetKernel() {
  struct utsname os_info {};
  uname(&os_info);
  return os_info.release;
}

std::string Fetchy::GetColorTag(int color, std::string icon) {
  std::string block = "█";
  std::string triangle = "";
  std::string tag = "";
  tag += Color::AnsiEscape(color) + block + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright, color + Color::to_bg) + icon + Color::reset;
  tag += Color::AnsiEscape(color, color + Color::to_bg_bright) + block + triangle + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright) + block + triangle + Color::reset;
  tag += " ";
  return tag;
}

std::string Fetchy::GetDiskCapacity(bool home_partition_exists) {
  std::filesystem::space_info space_info_home = std::filesystem::space("/home");
  std::filesystem::space_info space_info_root = std::filesystem::space("/");

  unsigned long long int capacity = space_info_root.capacity;
  if (home_partition_exists) capacity += space_info_home.capacity;
  capacity /= (1024 * 1024 * 1024);

  unsigned long long int free = space_info_root.free;
  if (home_partition_exists) free += space_info_home.free;
  free /= (1024 * 1024 * 1024);

  return std::to_string(capacity - free) + " / " + std::to_string(capacity) + "GB";
}

std::string Fetchy::BetweenDelimiter(std::string str, char delimiter) {
  size_t first = str.find_first_of(delimiter) + 1;
  size_t last = str.find_last_of(delimiter);

  return str.substr(first, last - first);
}

void Fetchy::Output() {
  std::cout
    << ASCII::Get(GetDistro())
    
    << "\n" 

    << GetColorTag(Color::black, "") + GetDistro()

    << "\n"

    << GetColorTag(Color::red, "󰜂") + GetArchitechture()

    << "\n"

    << GetColorTag(Color::green, "󰹣") + GetKernel()

    << "\n"

    << GetColorTag(Color::yellow, "󱩊") + GetDeviceName()

    << "\n"

    << GetColorTag(Color::blue, "") + GetCPU()

    << "\n"  

    << GetColorTag(Color::magenta, "󰹑") + GetGPU()   

    << "\n"

    << GetColorTag(Color::cyan, "") + GetMemory()

    << "\n"  

    << GetColorTag(Color::white, "") + GetDiskCapacity(true) 

    << "\n"      
    
    << std::endl;
}
} // namespace fetchy
