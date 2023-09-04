#include "ascii.h"

namespace fetchy {
std::string ASCII::GetASCII(std::string distro_name) {
    if (distro_name.find("Arch") != std::string::npos) {
        return arch;
    } else if (distro_name.find("Debian") != std::string::npos) {
        return debian;
    } else if (distro_name.find("Ubuntu") != std::string::npos) {
        return ubuntu;
    } else if (distro_name.find("Void") != std::string::npos) {
        return void_linux;   
    } else {
        return linux_catch_all;
    }
}
}