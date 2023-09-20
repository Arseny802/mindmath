#include "printer.h"

#include <cassert>
#include <iostream>

namespace mindmath::console {
printer::printer(statistic& o_statistic) : statistic_(o_statistic)
{

}

bool printer::solve_example(const example_view& o_example_view) const
{
    std::string str_number = helper_.number_to_string(
        statistic_.solved, statistic_.not_solved + statistic_.solved);

    bool result;
    std::remove_reference<decltype(o_example_view)>::type::AnswerType user_answer;
    do {
        std::cout << str_number << o_example_view.representation;
        std::cin >> user_answer;
        result = user_answer == o_example_view.answer;
    } while (!result && ++statistic_.mistakes < statistic_.max_mistakes);

    if (result) {
        statistic_.solved += 1;
        statistic_.not_solved -= 1;
    }

    return result;
}

std::string printer::helper::number_to_string(size_t index, size_t max_number) const
{
    assert(max_number > index);
    std::string result = "#";
    size_t number = index + 1;

    const int current_digits = count_digits(number);
    const int max_digits = count_digits(max_number);
    const int digits_diff = max_digits - current_digits;

    if (digits_diff > 0) {
        result += std::string(max_digits - current_digits, '0');
    }

    result += std::to_string(number) + ". ";
    return result;
}

int printer::helper::count_digits(size_t number) const
{
    int digits = 0;
    do {
        number /= 10;
        ++digits;
    } while (number);
    return digits;
}
} // namespace mindmath::console
