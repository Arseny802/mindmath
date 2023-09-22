#include <iostream>

#include "console/game.h"

int main() {
    bool result;
    try {
        result = mindmath::console::game().run();
    }
    catch(std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return EXIT_FAILURE;
    }

    if (result) {
        std::cout << "You passed Mindmath game! :)" << std::endl << std::endl;
        return EXIT_SUCCESS;
    } else {
        std::cout << "You failed Mindmath game! :(" << std::endl << std::endl;
        return EXIT_FAILURE;
    }
}
