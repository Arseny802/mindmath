#pragma once

namespace mindmath::common {

using type_t = uint16_t;
enum class type : type_t {
    UNDEFINED = 0,
    INTEGER = 1,
    FLOAT = 2,
    DOUBLE = 3,
    LONG = 4,
    LONG2 = 5,
    UNSIGNED_LONG = 6,
    UNSIGNED_LONG2 = 7,
};

} // namespace mindmath::common
