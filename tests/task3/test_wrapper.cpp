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

TEST_F(CalculateTest, WrapperChar) {
    Wrapper<char> w('A');
    EXPECT_EQ(w.value, 'A');
    EXPECT_EQ(Wrapper<char>::identity().value, '\0');
    Wrapper<char> sum = w + Wrapper<char>('B');
    EXPECT_NE(sum.value, 'A' + 'B');
}

TEST_F(CalculateTest, WrapperFloat) {
    Wrapper<float> w(1.25f);
    EXPECT_EQ(w.value, 1.25f);
    EXPECT_EQ(Wrapper<float>::identity().value, 0.f);
    Wrapper<float> sum = w + Wrapper<float>(1.24f);
    EXPECT_EQ(sum.value, 2.49f);
}

TEST_F(CalculateTest, WrapperBool) {
    Wrapper<bool> w(true);
    EXPECT_EQ(w.value, true);
    EXPECT_EQ(Wrapper<bool>::identity().value, false);
    Wrapper<bool> sum = w + Wrapper<bool>(false);
    EXPECT_EQ(sum.value, true);
}