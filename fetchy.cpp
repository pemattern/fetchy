#include "fetchy.h"
#include "color.h"
#include "ascii.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

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

std::string Fetchy::GetProcessor() { return "PROCESSOR"; }

std::string Fetchy::GetColorTag(int color) {
  std::string icon1 = "";
  std::string icon2 = "█";
  std::string icon3 = "";
  std::string tag = Color::AnsiEscape(color) + icon1 + icon2 + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright, color + Color::to_bg) +
         icon1 + Color::reset;
  tag += Color::AnsiEscape(color + Color::to_bright) + icon2 + icon3 +
         Color::reset;
  tag += " ";
  return tag;
}

std::string Fetchy::GetGridRow(std::string item1, std::string item2, int column_width) {
  int spacing_count = column_width - item1.length();
  std::string spacing = "";

  std::cout << std::to_string(spacing_count) << "\n";

  for (int i = 0; i < spacing_count; i++) {
    spacing += " ";
  }

  return item1 + spacing + item2;
}

std::string Fetchy::BetweenDelimiter(std::string str, char delimiter) {
  size_t first = str.find_first_of(delimiter) + 1;
  size_t last = str.find_last_of(delimiter);

  return str.substr(first, last - first);
}

void Fetchy::Output() {
  std::cout << "\n"
    << ASCII::arch_ascii << "\n" 

    << GetGridRow(GetColorTag(Color::black) + GetDistro() + " " + GetArchitechture(),
      GetColorTag(Color::blue) + GetDistro() + " " + GetArchitechture(), 48)

    << "\n"  

    << GetColorTag(Color::black) << GetDistro() << " " << GetArchitechture() << "\n" 
    << GetColorTag(Color::red) << GetDeviceName() << "\n"
    << GetColorTag(Color::green) << GetArchitechture() << "\n"
    << GetColorTag(Color::yellow) << GetProcessor() << "\n"
    << GetColorTag(Color::blue) << GetDistro() << " " << GetArchitechture() << "\n" 
    << GetColorTag(Color::magenta) << GetDeviceName() << "\n"
    << GetColorTag(Color::cyan) << GetArchitechture() << "\n"
    << GetColorTag(Color::white) << GetProcessor() << "\n"    
    
    << std::endl;
}
} // namespace fetchy
