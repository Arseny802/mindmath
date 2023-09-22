#pragma once

#include "statistic.h"
#include "common/setup.h"
#include "mindmath/generator.h"

namespace mindmath::console {
class game
{
public:
    game();

    bool run();

private:
    console::statistic statistic_{};
    common::setup setup_{};
    generator generator_{};
};
} // namespace mindmath::console
