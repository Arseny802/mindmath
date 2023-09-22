#include "gtest/gtest.h"
#include "console/printer.h"

namespace mindmath::console {

TEST(PrinterHelperTest, CountDigits1) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.count_digits(0), 1);
    EXPECT_EQ(o_helper.count_digits(1), 1);
    EXPECT_EQ(o_helper.count_digits(2), 1);
    EXPECT_EQ(o_helper.count_digits(9), 1);
}

TEST(PrinterHelperTest, CountDigits2) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.count_digits(10), 2);
    EXPECT_EQ(o_helper.count_digits(11), 2);
    EXPECT_EQ(o_helper.count_digits(12), 2);
    EXPECT_EQ(o_helper.count_digits(13), 2);

    EXPECT_EQ(o_helper.count_digits(20), 2);
    EXPECT_EQ(o_helper.count_digits(21), 2);
    EXPECT_EQ(o_helper.count_digits(22), 2);
    EXPECT_EQ(o_helper.count_digits(23), 2);

    EXPECT_EQ(o_helper.count_digits(70), 2);
    EXPECT_EQ(o_helper.count_digits(71), 2);
    EXPECT_EQ(o_helper.count_digits(72), 2);
    EXPECT_EQ(o_helper.count_digits(73), 2);
}

TEST(PrinterHelperTest, CountDigits3) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.count_digits(100), 3);
    EXPECT_EQ(o_helper.count_digits(101), 3);
    EXPECT_EQ(o_helper.count_digits(102), 3);
    EXPECT_EQ(o_helper.count_digits(103), 3);

    EXPECT_EQ(o_helper.count_digits(130), 3);
    EXPECT_EQ(o_helper.count_digits(131), 3);
    EXPECT_EQ(o_helper.count_digits(132), 3);
    EXPECT_EQ(o_helper.count_digits(133), 3);

    EXPECT_EQ(o_helper.count_digits(670), 3);
    EXPECT_EQ(o_helper.count_digits(671), 3);
    EXPECT_EQ(o_helper.count_digits(672), 3);
    EXPECT_EQ(o_helper.count_digits(673), 3);
}

TEST(PrinterHelperTest, CountDigits4) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.count_digits(0), 1);
    EXPECT_EQ(o_helper.count_digits(10), 2);
    EXPECT_EQ(o_helper.count_digits(100), 3);
    EXPECT_EQ(o_helper.count_digits(1000), 4);
    EXPECT_EQ(o_helper.count_digits(10000), 5);
    EXPECT_EQ(o_helper.count_digits(100000), 6);
    EXPECT_EQ(o_helper.count_digits(1000000), 7);
    EXPECT_EQ(o_helper.count_digits(10000000), 8);
    EXPECT_EQ(o_helper.count_digits(100000000), 9);
    EXPECT_EQ(o_helper.count_digits(1000000000), 10);
}

TEST(PrinterHelperTest, NumberToString1) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.number_to_string(0, 4), "#1. ");
    EXPECT_EQ(o_helper.number_to_string(1, 4), "#2. ");
    EXPECT_EQ(o_helper.number_to_string(2, 4), "#3. ");
    EXPECT_EQ(o_helper.number_to_string(3, 4), "#4. ");
}

TEST(PrinterHelperTest, NumberToString2) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.number_to_string(0, 9), "#1. ");
    EXPECT_EQ(o_helper.number_to_string(1, 9), "#2. ");
    EXPECT_EQ(o_helper.number_to_string(2, 9), "#3. ");
    EXPECT_EQ(o_helper.number_to_string(3, 9), "#4. ");
}

TEST(PrinterHelperTest, NumberToString3) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.number_to_string(0, 10), "#01. ");
    EXPECT_EQ(o_helper.number_to_string(1, 10), "#02. ");
    EXPECT_EQ(o_helper.number_to_string(2, 10), "#03. ");
    EXPECT_EQ(o_helper.number_to_string(3, 10), "#04. ");
}

TEST(PrinterHelperTest, NumberToString4) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.number_to_string(0, 100), "#001. ");
    EXPECT_EQ(o_helper.number_to_string(1, 100), "#002. ");
    EXPECT_EQ(o_helper.number_to_string(2, 100), "#003. ");
    EXPECT_EQ(o_helper.number_to_string(3, 100), "#004. ");
}

TEST(PrinterHelperTest, NumberToString5) {
    printer::helper o_helper;
    EXPECT_EQ(o_helper.number_to_string(0, 1000), "#0001. ");
    EXPECT_EQ(o_helper.number_to_string(10, 1000), "#0011. ");
    EXPECT_EQ(o_helper.number_to_string(100, 1000), "#0101. ");
    EXPECT_EQ(o_helper.number_to_string(999, 1000), "#1000. ");
}

} // namespace mindmath::console
