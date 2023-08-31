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

std::string Fetchy::GetColorTag(std::string color, std::string bg_color,
                                std::string bright_color,
                                std::string bg_bright_color) {
  std::string icon = "";
  std::string tag = color + icon + Color::end;
  tag += bright_color + bg_color + icon + Color::end;
  tag += Color::transparent + bg_bright_color + icon + Color::end;

  return tag;
}

std::string Fetchy::BetweenDelimiter(std::string str, char delimiter) {
  size_t first = str.find_first_of(delimiter) + 1;
  size_t last = str.find_last_of(delimiter);

  return str.substr(first, last - first);
}

void Fetchy::Output() {
  std::cout << GetColorTag(Color::magenta, Color::bg_magenta,
                           Color::bright_magenta, Color::bg_bright_magenta)
            << GetDistro() << " " << GetArchitechture() << std::endl;
}
} // namespace fetchy
