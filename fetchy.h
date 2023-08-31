#ifndef FETCHY_H_
#define FETCHY_H_

#include <string>

namespace fetchy {
class Fetchy {
public:
  Fetchy();

private:
  std::string GetDistro();
  std::string GetArchitechture();
  std::string GetDeviceName();
  std::string GetProcessor();

  std::string GetColorTag(std::string color, std::string bg_color,
                          std::string bright_color,
                          std::string bg_bright_color);

  std::string BetweenDelimiter(std::string str, char delimiter);

  void Output();
};
} // namespace fetchy

#endif
