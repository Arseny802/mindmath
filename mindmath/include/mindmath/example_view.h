#pragma once

#include <string>

namespace mindmath {

template<typename AnswerT = int>
struct example_view_t
{
    using AnswerType = AnswerT;

    std::string representation;
    AnswerT answer;
};

using example_view = example_view_t<>;

}  // namespace mindmath
