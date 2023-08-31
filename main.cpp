#include "fetchy.h"

#include <iostream>

int main(int argc, char *argv[]) {
    fetchy::Fetchy fetchy;
    fetchy.OS();

    std::string input;
    std::cin >> input;

    return EXIT_SUCCESS;
}