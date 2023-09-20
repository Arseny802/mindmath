#pragma once

#include "statistic.h"
#include "mindmath/example_view.h"

namespace mindmath::console {
class printer
{
public:
    printer(statistic& o_statistic);

    bool solve_example(const example_view& example_view) const;

    class helper
    {
    public:
        int count_digits(size_t number) const;
        std::string number_to_string(size_t index, size_t max_number) const;
    };

private:
    helper helper_;
    statistic& statistic_;
};
} // namespace mindmath::console
