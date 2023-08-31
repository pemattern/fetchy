#include "fetchy.h"

#include <iostream>

namespace fetchy {
    Fetchy::Fetchy() {
        Output();
    }

    std::string Fetchy::GetDistro() {
        return "DISTRO";
    }

    std::string Fetchy::GetDeviceName() {
        return "DEVICE NAME";
    }

    std::string Fetchy::GetProcessor() {
        return "PROCESSOR";
    }

    void Fetchy::Output() {
        std::cout << GetDistro() << GetDeviceName() << GetProcessor() << std::endl;
    }
}