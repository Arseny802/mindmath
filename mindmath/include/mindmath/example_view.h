#pragma once

#include <string>
#include <vector>

namespace mindmath {

template<typename AnswerT = int>
struct example_view_t
{
    using AnswerType = AnswerT;

    std::string representation;
    AnswerT answer;
};

//decltype(example_view_t<>::representation)

using example_view = example_view_t<>;
using example_views = std::vector<example_view>;
using example_views_float = std::vector<example_view_t<float>>;
using example_views_double = std::vector<example_view_t<double>>;
using example_views_long = std::vector<example_view_t<long>>;
using example_views_long2 = std::vector<example_view_t<long long>>;
using example_views_ulong = std::vector<example_view_t<unsigned long>>;
using example_views_ulong2 = std::vector<example_view_t<unsigned long long>>;

}  // namespace mindmath
