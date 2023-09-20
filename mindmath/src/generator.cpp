#include "mindmath/generator.h"

namespace mindmath {
void generator::setup(common::setup new_setup)
{
    setup_ = std::move(new_setup);
}

example_views generator::create()
{
    example_views result;

    {
        example_view test_example;
        test_example.representation = "2 + 2 = ";
        test_example.answer = 4;

        result.emplace_back(test_example);
    }

    {
        example_view test_example;
        test_example.representation = "2 * 2 = ";
        test_example.answer = 4;

        result.emplace_back(test_example);
    }

    return result;
}

} // namespace mindmath
