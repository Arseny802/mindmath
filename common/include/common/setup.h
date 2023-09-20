#pragma once

#include "operation.h"
#include "type.h"

namespace mindmath::common {

constexpr size_t DEFAULT_EXAMPLES_AMOUNT = 42;
constexpr size_t DEFAULT_MAX_ARGUMENTS = 2;
constexpr operation_t DEFAULT_ALLOWED_OPERATIONS = static_cast<operation_t>(operation::ALL);
constexpr type_t DEFAULT_ANSWER_TYPE = static_cast<type_t>(type::INTEGER);

struct setup {
    void set_allowed_operations(operation allowed_operations_mask);
    void set_allowed_operations(operation_t allowed_operations_mask);
    void set_answer_type(type answer_type);
    void set_answer_type(type_t answer_type);

    long long argument_value_min = 0;
    long long argument_value_max = 100;

    size_t examples_amount = DEFAULT_EXAMPLES_AMOUNT;
    size_t max_arguments = DEFAULT_MAX_ARGUMENTS;
    operation_t allowed_operations = DEFAULT_ALLOWED_OPERATIONS;
    type_t answer_type = DEFAULT_ANSWER_TYPE;
};

} // namespace mindmath::common
