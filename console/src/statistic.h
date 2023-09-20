#pragma once

namespace mindmath::console {

struct statistic {
    size_t mistakes = 0;
    size_t max_mistakes = 2;
    size_t solved = 0;
    size_t not_solved;
};

} // namespace mindmath::console
