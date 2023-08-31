#ifndef COLOR_H_
#define COLOR_H_

#include <string>

namespace fetchy {
class Color {
public:
  inline const static std::string transparent = "\e[0;39m";
  inline const static std::string bg_transparent = "\e[0;49m";

  inline const static std::string black = "\e[0;30m";
  inline const static std::string red = "\e[0;31m";
  inline const static std::string green = "\e[0;32m";
  inline const static std::string yellow = "\e[0;33m";
  inline const static std::string blue = "\e[0;34m";
  inline const static std::string magenta = "\e[0;35m";
  inline const static std::string cyan = "\e[0;36m";
  inline const static std::string white = "\e[0;37m";

  inline const static std::string bg_black = "\e[0;40m";
  inline const static std::string bg_red = "\e[0;41m";
  inline const static std::string bg_green = "\e[0;42m";
  inline const static std::string bg_yellow = "\e[0;43m";
  inline const static std::string bg_blue = "\e[0;44m";
  inline const static std::string bg_magenta = "\e[0;45m";
  inline const static std::string bg_cyan = "\e[0;46m";
  inline const static std::string bg_white = "\e[0;47m";

  inline const static std::string bright_black = "\e[0;90m";
  inline const static std::string bright_red = "\e[0;91m";
  inline const static std::string bright_green = "\e[0;92m";
  inline const static std::string bright_yellow = "\e[0;93m";
  inline const static std::string bright_blue = "\e[0;94m";
  inline const static std::string bright_magenta = "\e[0;95m";
  inline const static std::string bright_cyan = "\e[0;96m";
  inline const static std::string bright_white = "\e[0;97m";

  inline const static std::string bg_bright_black = "\e[0;100m";
  inline const static std::string bg_bright_red = "\e[0;101m";
  inline const static std::string bg_bright_green = "\e[0;102m";
  inline const static std::string bg_bright_yellow = "\e[0;103m";
  inline const static std::string bg_bright_blue = "\e[0;104m";
  inline const static std::string bg_bright_magenta = "\e[0;105m";
  inline const static std::string bg_bright_cyan = "\e[0;106m";
  inline const static std::string bg_bright_white = "\e[0;107m";

  inline const static std::string end = "\e[0m";
};
} // namespace fetchy

#endif
