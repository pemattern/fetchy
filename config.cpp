#include "config.h"

#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <iostream>

namespace fetchy {
std::string Config::GetContent() {
    std::stringstream buffer;
    std::ifstream config_stream(home_dir_ + config_dir_ + fetchy_dir_ + fetchy_file_);
    if (!config_stream)
    {
        if (!std::filesystem::exists(home_dir_ + config_dir_))
            std::filesystem::create_directory(home_dir_ + config_dir_);

        if (!std::filesystem::exists(home_dir_ + config_dir_ + fetchy_dir_))
            std::filesystem::create_directory(home_dir_ + config_dir_ + fetchy_dir_);

        std::filesystem::copy(fetchy_file_, home_dir_ + config_dir_ + fetchy_dir_);
        config_stream.open(fetchy_file_);
    }
    buffer << config_stream.rdbuf();
    config_stream.close();
    return buffer.str();
}

Config::Config() {
    home_dir_ = getenv("HOME");
    config_ = GetContent();
}
}