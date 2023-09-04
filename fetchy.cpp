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
  return "No CPU";
}

std::string Fetchy::GetGPU() {
  return "NOT IMPLEMENTED";
}

std::string Fetchy::GetMemory() {
  long pages = sysconf(_SC_PHYS_PAGES);
  long page_size = sysconf(_SC_PAGE_SIZE);
  int divisor = 1024;
  unsigned long long int total_memory = pages * page_size;
  int total_memory_gb = total_memory / 1024 / 1024 / 1024;
  return std::to_string(total_memory_gb + 1) + "GB";
}

std::string Fetchy::GetKernel() {
  struct utsname os_info {};
  uname(&os_info);
  return os_info.release;
}

std::string Fetchy::GetColorTag(int color, std::string entryIcon) {
  std::string tri_bottom = "";
  std::string block = "█";
  std::string tri_top = "";
  std::string tag = Color::AnsiEscape(color) + block + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright, color + Color::to_bg) + entryIcon + Color::reset;
  tag += Color::AnsiEscape(color, color + Color::to_bg_bright) + block + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright, color + Color::to_bg) + tri_bottom + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright) + block + tri_top + Color::reset;
  tag += " ";
  return tag;
}

std::string Fetchy::GetDiskCapacity() {
  std::filesystem::space_info space_info_home = std::filesystem::space("/home");
  std::filesystem::space_info space_info_root = std::filesystem::space("/");

  unsigned long long int capacity = space_info_home.capacity + space_info_root.capacity;
  capacity /= (1024 * 1024 * 1024);

  return std::to_string(capacity + 1) + "GB";
}

std::string Fetchy::BetweenDelimiter(std::string str, char delimiter) {
  size_t first = str.find_first_of(delimiter) + 1;
  size_t last = str.find_last_of(delimiter);

  return str.substr(first, last - first);
}

void Fetchy::Output() {
  std::cout
    << ASCII::GetASCII("Ubunt")
    
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

    << GetColorTag(Color::white, "") + GetDiskCapacity() 

    << "\n"      
    
    << std::endl;
}
} // namespace fetchy
