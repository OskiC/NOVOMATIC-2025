//
// Created by xoska on 23.04.2025.
//
#include <gtest/gtest.h>
#include "calculate.h"


class CalculateTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(CalculateTest, CalculateFuncIntTest) {
    Wrapper<int> val(2);
    int n = 3;

    auto result = calculate(n, val, BinaryOp<int>{});

    EXPECT_EQ(result.value, 6);
}

TEST_F(CalculateTest, CalculateFuncStringTest) {
    Wrapper<std::string> val("ab");
    int n = 3;

    auto result = calculate(n, val, BinaryOp<std::string>{});

    EXPECT_EQ(result.value, "ababab");
}

TEST_F(CalculateTest, CalculateFuncFloatTest) {
    Wrapper<float> val(1.2f);
    int n = 3;

    auto result = calculate(n, val, BinaryOp<float>{});

    EXPECT_EQ(result.value, 3.6f);
}

TEST_F(CalculateTest, CalculateFuncDoubleTest) {
    Wrapper<double> val(1.3);
    int n = 3;

    auto result = calculate(n, val, BinaryOp<double>{});

    EXPECT_EQ(result.value, 3.9);
}

TEST_F(CalculateTest, CalculateFuncBoolTest) {
    Wrapper<bool> val(true);
    int n = 3;

    auto result = calculate(n, val, BinaryOp<bool>{});

    EXPECT_EQ(result.value, true);

    int m = 4;

    auto result2 = calculate(m, val, BinaryOp<bool>{});

    EXPECT_EQ(result2.value, false);
}