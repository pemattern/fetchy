#ifndef COLOR_H_
#define COLOR_H_

#include <string>

namespace fetchy {
class Color {
public:
  static inline const int to_bg = 10;
  static inline const int to_bright = 60;
  static inline const int to_bg_bright = 70;

  static inline const int def = 39;
  static inline const int black = 30;
  static inline const int red = 31;
  static inline const int green = 32;
  static inline const int yellow = 33;
  static inline const int blue = 34;
  static inline const int magenta = 35;
  static inline const int cyan = 36;
  static inline const int white = 37;

  static inline const std::string reset = "\e[0m";

  static std::string AnsiEscape(int fg_color) {
    std::string str = "\e[";
    str += std::to_string(fg_color);
    str += "m";
    return str;
  };

  static std::string AnsiEscape(int fg_color, int bg_color) {
    std::string str = "\e[";
    str += std::to_string(fg_color);
    str += ";";
    str += std::to_string(bg_color);
    str += "m";
    return str;
  }
};
} // namespace fetchy

#endif
