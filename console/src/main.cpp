#include <iostream>
#include <string_view>

#include "statistic.h"
#include "printer.h"
#include "mindmath/example_view.h"
#include "mindmath/generator.h"

using namespace mindmath;

int main() {
    std::cout << std::endl << "Starting Mindmath game!" << std::endl << std::endl;

    setup o_setup;
    o_setup.max_arguments = 3;

    decltype(o_setup) o_setup2;
    o_setup2.max_arguments = 3;

    generator o_generator(o_setup);
    const auto to_solve = o_generator.create();

    console::statistic o_statistic;
    o_statistic.not_solved = to_solve.size();
    o_statistic.max_mistakes *= o_statistic.not_solved;

    std::cout << "You should solve " << o_statistic.not_solved << " examples." << std::endl;
    std::cout << "Max mistakes for all game: " << o_statistic.max_mistakes << "." << std::endl;
    std::cout << std::endl;

    try {
        console::printer o_printer(o_statistic);
        for (const auto& example : to_solve) {
            o_printer.solve_example(example);
        }
        std::cout << std::endl;
    }
    catch(std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return EXIT_FAILURE;
    }

    if (o_statistic.not_solved) {
        std::cout << "You failed Mindmath game! :(" << std::endl << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << "You passed Mindmath game! :)" << std::endl << std::endl;
        return EXIT_SUCCESS;
    }
}
