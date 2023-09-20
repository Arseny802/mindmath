#include "mindmath/generator.h"

#include <optional>
#include <random>

namespace mindmath {
namespace {
// Seed with a real random value, if available
std::random_device random_device;

template<typename resT = int>
resT gen_random_number(resT between_min, resT between_max)
{
    std::default_random_engine random_engine(random_device());
    std::uniform_int_distribution<resT> uniform_dist(between_min, between_max);
    return uniform_dist(random_engine);
}
}

void generator::setup(common::setup new_setup)
{
    setup_ = std::move(new_setup);
}

example_views generator::create()
{
    using AnswerType = decltype(create())::value_type::AnswerType;
    std::vector<example_view_t<AnswerType>> result;

    for (size_t i = 0; i < setup_.examples_amount; ++i) {
        auto example_result = gen_argument();
        std::string representation = std::to_string(example_result) + " ";

        size_t operation_number = 1;
        std::vector<common::operation> operations(setup_.max_arguments - 1);
        std::vector<std::optional<AnswerType>> arguments(setup_.max_arguments);
        arguments[0] = example_result;
        do {
            const auto operation = gen_operation();
            const auto arg = gen_argument();

            representation += operation_to_representation(operation) + " ";
            representation += std::to_string(arg) + " ";
            operations[operation_number - 1] = operation;
            arguments[operation_number] = arg;

        } while (++operation_number < setup_.max_arguments);
        representation += "= ";

        for (size_t k = 0; k < operations.size(); ++k)
        {
            if (operations[k] == common::operation::MULTIPLICATION) {
                arguments[k + 1] = arguments[k].value() * arguments[k + 1].value();
                arguments[k] = std::nullopt;
            }
            else if (operations[k] == common::operation::DIVISION) {
                arguments[k + 1] = arguments[k].value() / arguments[k + 1].value();
                arguments[k] = std::nullopt;
            }
        }

        size_t k = 0;
        while (!arguments[k].has_value()) {
            ++k;
        }
        example_result = arguments[k].value();

        for (; k < operations.size(); ++k)
        {
            if (operations[k] == common::operation::ADDITION) {
                while (!arguments[k + 1].has_value()) { ++k; }
                example_result += arguments[k + 1].value();
            }
            else if (operations[k] == common::operation::SUBTRACTION) {
                while (!arguments[k + 1].has_value()) { ++k; }
                example_result -= arguments[k + 1].value();
            }
        }

        example_view test_example;
        test_example.representation = std::move(representation);
        test_example.answer = example_result;
        result.emplace_back(test_example);
    }

    return result;
}

int generator::gen_argument() const
{
    return gen_random_number<decltype(gen_argument())>(
        setup_.argument_value_min, setup_.argument_value_max);
}

common::operation generator::gen_operation() const
{
    int random_number = gen_random_number<int>(1, 4);
    switch (gen_random_number<int>(1, 4)) {
        case 1:
            return common::operation::ADDITION;
        case 2:
            return common::operation::SUBTRACTION;
        case 3:
            return common::operation::MULTIPLICATION;
        case 4:
            return common::operation::DIVISION;
        default:
            return common::operation::ADDITION;
    }
}

generator::operation_representation_t generator::operation_to_representation(common::operation operation)
{
    switch (operation) {
        case common::operation::ADDITION:
            return generator::operation_representation_t("+");
        case common::operation::SUBTRACTION:
            return generator::operation_representation_t("-");
        case common::operation::MULTIPLICATION:
            return generator::operation_representation_t("*");
        case common::operation::DIVISION:
            return generator::operation_representation_t("/");
    }
}

} // namespace mindmath
