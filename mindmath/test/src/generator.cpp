#include "gtest/gtest.h"
#include "mindmath/example_view.h"
#include "mindmath/generator.h"

namespace {
inline void DefaultTestSet(const std::vector<mindmath::example_view>& generated_set) {
    for (const auto& item : generated_set) {
        EXPECT_TRUE(!item.representation.empty());
    }
}
}

TEST(MindmathGeneratorTest, EmptySet) {
    mindmath::generator o_generator;
    mindmath::common::setup empty_setup;

    o_generator.setup(empty_setup);
    const auto result = o_generator.create();
    DefaultTestSet(result);
}

TEST(MindmathGeneratorTest, Test1) {
    mindmath::generator o_generator;
    mindmath::common::setup o_setup;
    o_setup.allowed_operations = static_cast<uint16_t>(mindmath::common::operation::NONE);

    o_generator.setup(o_setup);
    const auto result = o_generator.create();
    DefaultTestSet(result);
}

TEST(MindmathGeneratorTest, Test2) {
    mindmath::generator o_generator;
    mindmath::common::setup o_setup;
    o_setup.max_arguments = 3;

    o_generator.setup(o_setup);
    const auto result = o_generator.create();
    DefaultTestSet(result);
}
