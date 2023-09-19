#include "mindmath/generator.h"

namespace mindmath {
generator::generator(setup new_setup) : setup_(std::move(new_setup))
{

}

std::vector<example_view> generator::create()
{
    std::vector<example_view> result;

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
