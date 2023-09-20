#pragma once

#include "example_view.h"
#include "common/setup.h"

#include <vector>

namespace mindmath {

class generator {
public:
    void setup(common::setup new_setup);
    example_views create();

    using operation_representation_t = decltype(example_view_t<>::representation);
    static operation_representation_t operation_to_representation(common::operation operation);
private:
    int gen_argument() const;
    common::operation gen_operation() const;


    common::setup setup_;
};

} // namespace mindmath
