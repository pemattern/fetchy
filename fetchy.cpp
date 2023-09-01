#include "fetchy.h"
#include "color.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

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

std::string Fetchy::GetDeviceName() { return "DEVICE NAME"; }

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

  return tag;
}

std::string Fetchy::BetweenDelimiter(std::string str, char delimiter) {
  size_t first = str.find_first_of(delimiter) + 1;
  size_t last = str.find_last_of(delimiter);

  return str.substr(first, last - first);
}

void Fetchy::Output() {
  std::cout << GetColorTag(Color::magenta) << GetDistro() << " "
            << GetArchitechture() << std::endl;
}
} // namespace fetchy
