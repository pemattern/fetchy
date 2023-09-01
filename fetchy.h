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

  std::string GetColorTag(int color);

  std::string BetweenDelimiter(std::string str, char delimiter);

  void Output();
};
} // namespace fetchy

#endif
