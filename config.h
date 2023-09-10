#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

namespace fetchy {
class Config {
private:
    std::string GetContent();
    std::string config_raw_;
    std::string home_dir_;
    static inline std::string config_dir_ = "/.config";
    static inline std::string fetchy_dir_ = "/fetchy/";
    static inline std::string fetchy_file_ = "fetchy.conf";

public:
    Config();
};
}

#endif