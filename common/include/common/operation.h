#pragma once
#include <stdint.h>

namespace mindmath::common {

using operation_t = uint16_t;
enum class operation : operation_t {
    NONE = 0,
    ADDITION = 1,
    SUBTRACTION = 2,
    MULTIPLICATION = 4,
    DIVISION = 8,
    ALL = ADDITION + SUBTRACTION + MULTIPLICATION + DIVISION,
    PRIO_1 = MULTIPLICATION + DIVISION,
    PRIO_2 = ADDITION + SUBTRACTION,
};

} // namespace mindmath::common
