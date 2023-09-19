#include "gtest/gtest.h"
#include "mindmath/example_view.h"
#include "mindmath/generator.h"
#include "mindmath/operation.h"

namespace {
inline void DefaultTestSet(const std::vector<mindmath::example_view>& generated_set) {
    for (const auto& item : generated_set) {
        EXPECT_TRUE(!item.representation.empty());
    }
}
}

TEST(MindmathGeneratorTest, EmptySet) {
    mindmath::setup empty_setup;

    const auto result = mindmath::generator(empty_setup).create();
    DefaultTestSet(result);
}

TEST(MindmathGeneratorTest, Test1) {
    mindmath::setup setup;
    setup.allowed_operations = static_cast<uint16_t>(mindmath::operation::NONE);

    const auto result = mindmath::generator(setup).create();
    DefaultTestSet(result);
}

TEST(MindmathGeneratorTest, Test2) {
    mindmath::setup setup;
    setup.max_arguments = 3;

    const auto result = mindmath::generator(setup).create();
    DefaultTestSet(result);
}
