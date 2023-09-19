#include <iostream>
#include <string_view>

#include "mindmath/example_view.h"
#include "mindmath/generator.h"

struct statistic {
    size_t mistakes = 0;
    size_t max_mistakes = 2;
    size_t solved = 0;
    size_t not_solved;
};

std::string number_to_string(size_t number, size_t max_number)
{
    std::string result = "#";

    result +=". ";
    return result;
}

bool solve_example(const mindmath::example_view& example_view, statistic& o_statistic) {
    std::string str_number = number_to_string(o_statistic.solved, o_statistic.not_solved + o_statistic.solved);
    bool result;
    mindmath::example_view::AnswerType user_answer;
    do {
        std::cout << str_number << example_view.representation;
        std::cin >> user_answer;
        result = user_answer == example_view.answer;
    } while (!result && ++o_statistic.mistakes < o_statistic.max_mistakes);

    if (result) {
        o_statistic.solved += 1;
        o_statistic.not_solved -= 1;
    }

    return result;
}

int main() {
    std::cout << std::endl << "Starting Mindmath game!" << std::endl << std::endl;

    mindmath::setup o_setup;
    o_setup.max_arguments = 3;

    mindmath::generator o_generator(o_setup);
    const auto to_solve = o_generator.create();

    statistic o_statistic;
    o_statistic.not_solved = to_solve.size();
    o_statistic.max_mistakes *= o_statistic.not_solved;

    std::cout << "You should solve " << o_statistic.not_solved << " examples." << std::endl;
    std::cout << "Max mistakes for all game: " << o_statistic.max_mistakes << "." << std::endl;
    std::cout << std::endl;

    try {
        for (const auto& example : to_solve) {
            solve_example(example, o_statistic);
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
