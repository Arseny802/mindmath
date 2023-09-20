#include "common/setup.h"

namespace mindmath::common {

void setup::set_allowed_operations(operation allowed_operations_mask)
{
    this->allowed_operations = static_cast<type_t>(allowed_operations_mask);
}

void setup::set_allowed_operations(operation_t allowed_operations_mask)
{
    this->allowed_operations = allowed_operations_mask;
}

void setup::set_answer_type(type answer_type)
{
    this->answer_type = static_cast<type_t>(answer_type);
}

void setup::set_answer_type(type_t answer_type)
{
    this->answer_type = answer_type;
}

} // namespace mindmath::common
