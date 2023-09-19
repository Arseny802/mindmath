#pragma once

namespace mindmath {



enum class operation : uint16_t {
    NONE = 0,
    ADDITION = 1,
    SUBTRACTION = 2,
    MULTIPLICATION = 4,
    DIVISION = 8,
    ALL = ADDITION + SUBTRACTION + MULTIPLICATION + DIVISION
};

} // namespace mindmath
