#pragma once

#include "operation.h"

namespace mindmath::common {

constexpr size_t DEFAULT_EXAMPLES_AMOUNT = 42;
constexpr size_t DEFAULT_MAX_ARGUMENTS = 2;
constexpr uint16_t DEFAULT_ALLOWED_OPERATIONS = static_cast<uint16_t>(operation::ALL);

struct setup {
    size_t examples_amount = DEFAULT_EXAMPLES_AMOUNT;
    size_t max_arguments = DEFAULT_MAX_ARGUMENTS;
    uint16_t allowed_operations = DEFAULT_ALLOWED_OPERATIONS;
};

} // namespace mindmath::common
