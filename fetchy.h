#ifndef FETCHY_H_
#define FETCHY_H_

#include <string>

namespace fetchy {
    class Fetchy {
    public:
        Fetchy();

        std::string GetDistro();
        std::string GetDeviceName();
        std::string GetProcessor();

        void Output();
    };
}

#endif