#include "game.h"
#include "printer.h"
#include <iostream>

namespace mindmath::console {
game::game()
{
    setup_.max_arguments = 3;
    generator_.setup(setup_);
}

bool game::run()
{
    std::cout << std::endl << "Starting Mindmath game!" << std::endl << std::endl;

    std::cout << "Generating examples...  ";
    const example_views to_solve = generator_.create();
    std::cout << "Ok." << std::endl;

    statistic_.not_solved = to_solve.size();
    statistic_.max_mistakes *= statistic_.not_solved;

    std::cout << "You should solve " << statistic_.not_solved << " examples." << std::endl;
    std::cout << "Max mistakes for all game: " << statistic_.max_mistakes << "." << std::endl;
    std::cout << std::endl;

    console::printer o_printer(statistic_);
    for (const auto& example : to_solve) {
        o_printer.solve_example(example);
    }
    std::cout << std::endl;

    return statistic_.not_solved == 0;
}
} // namespace mindmath::console
