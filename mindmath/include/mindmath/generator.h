#pragma once

#include "example_view.h"
#include "common/setup.h"

#include <vector>

namespace mindmath {

class generator {
public:
    void setup(common::setup new_setup);
    example_views create();

private:
    common::setup setup_;
};

} // namespace mindmath
