#pragma once

#include "example_view.h"
#include "setup.h"

#include <vector>

namespace mindmath {

class generator {
public:
    generator(setup new_setup);
    std::vector<example_view> create();

private:
    setup setup_;
};

} // namespace mindmath
