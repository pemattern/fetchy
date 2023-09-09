#include "config.h"

#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

namespace fetchy {
std::string Config::GetContent() {
    std::ifstream config_stream(home_dir_ + config_dir_ + fetchy_dir_ + fetchy_file_);
    if (!config_stream)
    {
        if (!std::filesystem::exists(home_dir_ + config_dir_))
            std::filesystem::create_directory(home_dir_ + config_dir_);

        if (!std::filesystem::exists(home_dir_ + config_dir_ + fetchy_dir_))
            std::filesystem::create_directory(home_dir_ + config_dir_ + fetchy_dir_);

        std::ofstream create_config(home_dir_ + config_dir_ + fetchy_dir_ + fetchy_file_);
        create_config << "Config"; // Replace with default config.
        create_config.close();
        return "Config";
    }
    std::stringstream buffer;
    buffer << config_stream.rdbuf();
    return buffer.str();
};

Config::Config() {
    home_dir_ = getenv("HOME");
    config_ = GetContent();
}
}