#include "ascii.h"

namespace fetchy {
std::string ASCII::Get(std::string distro_name) {
    if (distro_name.find("Arch") != std::string::npos) {
        return arch;
    } else if (distro_name.find("Debian") != std::string::npos) {
        return debian;
    } else if (distro_name.find("Fedora") != std::string::npos) {
        return fedora;  
    } else if (distro_name.find("Mint") != std::string::npos) {
        return linux_mint;
    } else if (distro_name.find("Nix") != std::string::npos) {
        return nixos;      
    } else if (distro_name.find("openSUSE") != std::string::npos) {
        return opensuse;   
    } else if (distro_name.find("Pop") != std::string::npos) {
        return pop_os;   
    } else if (distro_name.find("Ubuntu") != std::string::npos) {
        return ubuntu;
    } else if (distro_name.find("Void") != std::string::npos) {
        return void_linux;   
    } else {
        return linux_catch_all;
    }
}
}