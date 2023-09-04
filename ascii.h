#ifndef ASCII_H_
#define ASCII_H_

#include <string>

namespace fetchy {
class ASCII {
public:
    static std::string GetASCII(std::string distro_name);
private:
    // ASCII FONT NAME: SLANT
    inline static std::string arch =
        "    ___              __   \n"
        "   /   |  __________/ /_  \n"
        "  / /| | / ___/ ___/ __ \\ \n"
        " / ___ |/ /  / /__/ / / / \n"
        "/_/  |_/_/   \\___/_/ /_/  \n";

    inline static std::string debian = 
        "    ____       __    _           \n"
        "   / __ \\___  / /_  (_)___ _____ \n"
        "  / / / / _ \\/ __ \\/ / __ `/ __ \\\n"
        " / /_/ /  __/ /_/ / / /_/ / / / /\n"
        "/_____/\\___/_.___/_/\\__,_/_/ /_/ \n";

    inline static std::string ubuntu =
        "   __  ____                __       \n"
        "  / / / / /_  __  ______  / /___  __\n"
        " / / / / __ \\/ / / / __ \\/ __/ / / /\n"
        "/ /_/ / /_/ / /_/ / / / / /_/ /_/ / \n"
        "\\____/_.___/\\__,_/_/ /_/\\__/\\__,_/  \n";

    inline static std::string void_linux =
        " _    __      _     __\n"
        "| |  / /___  (_)___/ /\n"
        "| | / / __ \\/ / __  / \n"
        "| |/ / /_/ / / /_/ /  \n"
        "|___/\\____/_/\\__,_/   \n";
                       
    inline static std::string linux_catch_all =
        "    __    _                 \n"
        "   / /   (_)___  __  ___  __\n"
        "  / /   / / __ \\/ / / / |/_/\n"
        " / /___/ / / / / /_/ />  <  \n"
        "/_____/_/_/ /_/\\__,_/_/|_|  \n";
                            



                                 

                                                 
};
} // namespace fetchy

#endif