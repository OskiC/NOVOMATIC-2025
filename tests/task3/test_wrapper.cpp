//
// Created by xoska on 22.04.2025.
//
#include <gtest/gtest.h>
#include "Wrapper.h"

class CalculateTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(CalculateTest, WrapperInt) {
    Wrapper<int> w(5);
    EXPECT_EQ(w.value, 5);
    EXPECT_EQ(Wrapper<int>::identity().value, 0);
    Wrapper<int> sum = w + Wrapper<int>(3);
    EXPECT_EQ(sum.value, 8);
}

TEST_F(CalculateTest, WrapperString) {
    Wrapper<std::string> w("hej");
    EXPECT_EQ(w.value, "hej");
    EXPECT_EQ(Wrapper<std::string>::identity().value, "");
    Wrapper<std::string> sum = w + Wrapper<std::string>("ho");
    EXPECT_EQ(sum.value, "hejho");
}

TEST_F(CalculateTest, WrapperDouble) {
    Wrapper<double> w(2.3);
    EXPECT_EQ(w.value, 2.3);
    EXPECT_EQ(Wrapper<double>::identity().value, 0);
    Wrapper<double> sum = w + Wrapper<double>(1.2);
    EXPECT_EQ(sum.value, 3.5);
}
