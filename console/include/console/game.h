#pragma once
#include <memory>

#include "statistic.h"
#include "common/setup.h"
#include "mindmath/generator.h"

namespace mindmath::console {
class game
{
public:
    game();
    ~game();

    bool run();

private:
    console::statistic statistic_{};
    std::unique_ptr<common::setup> setup_{};
    generator generator_{};
};
} // namespace mindmath::console
