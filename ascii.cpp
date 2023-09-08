#include "ascii.h"

#include <algorithm>

namespace fetchy
{
    std::string ASCII::Get(std::string distro_name)
    {
        std::transform(distro_name.begin(), distro_name.end(), distro_name.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
        if (distro_name.find("arch") != std::string::npos)
        {
            return arch;
        }
        else if (distro_name.find("debian") != std::string::npos)
        {
            return debian;
        }
        else if (distro_name.find("fedora") != std::string::npos)
        {
            return fedora;
        }
        else if (distro_name.find("mint") != std::string::npos)
        {
            return linux_mint;
        }
        else if (distro_name.find("nix") != std::string::npos)
        {
            return nixos;
        }
        else if (distro_name.find("opensuse") != std::string::npos)
        {
            return opensuse;
        }
        else if (distro_name.find("pop") != std::string::npos)
        {
            return pop_os;
        }
        else if (distro_name.find("ubuntu") != std::string::npos)
        {
            return ubuntu;
        }
        else if (distro_name.find("void") != std::string::npos)
        {
            return void_linux;
        }
        else
        {
            return linux_catch_all;
        }
    }
}