#include "console/game.h"
#include "console/printer.h"
#include "config/config_parser_factory.h"
#include <iostream>

namespace mindmath::console {
namespace {
constexpr config::parsing_types DEFAULT_CONFIG_TYPE = config::parsing_types::ini;
const std::string DEFAULT_CONFIG_FILENAME = "mindmath_config.ini";
}

game::game() = default;
game::~game() = default;

bool game::run()
{
    std::cout << std::endl << "Starting Mindmath game!" << std::endl << std::endl;

    {
        auto parser = config::config_parser_factory::generate_parser(DEFAULT_CONFIG_TYPE);
        parser->read(DEFAULT_CONFIG_FILENAME);
        setup_ = parser->get_setup();
        generator_.setup(*setup_);
    }

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
        if (!o_printer.solve_example(example)) {
            break; // game failed
        }
    }
    std::cout << std::endl;

    return statistic_.not_solved == 0;
}
} // namespace mindmath::console
