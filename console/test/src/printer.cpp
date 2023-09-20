#include "gtest/gtest.h"
#include "../../src/printer.h"

namespace mindmath::console {

TEST(PrinterTest, Test1) {
    console::statistic o_statistic;
    printer o_printer(o_statistic);
}

} // namespace mindmath::console
