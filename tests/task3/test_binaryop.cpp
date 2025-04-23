//
// Created by xoska on 22.04.2025.
//
#include <gtest/gtest.h>
#include "binary_op.h"

class CalculateTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(CalculateTest, BinaryOpInt) {
    BinaryOp<int> op;
    Wrapper<int> a(5), b(3);
    Wrapper<int> result = op(a,b);
    EXPECT_EQ(result.value, 8);
}

TEST_F(CalculateTest, BinaryOpString) {
    BinaryOp<std::string> op;
    Wrapper<std::string> a("hej"), b("ho");
    Wrapper<std::string> result = op(a,b);
    EXPECT_EQ(result.value, "hejho");
}

TEST_F(CalculateTest, BinaryOpDouble) {
    BinaryOp<double> op;
    Wrapper<double> a(2.3), b(1.2);
    Wrapper<double> result = op(a, b);
    EXPECT_EQ(result.value, 3.5);
}

TEST_F(CalculateTest, BinayOpChar) {
    BinaryOp<char> op;
    Wrapper<char> a('a'), b('b');
    Wrapper<char> result = op(a, b);
    EXPECT_EQ(result.value, std::vector<char>({'a','b'}));
}

TEST_F(CalculateTest, BinaryOpFloat) {
    BinaryOp<float> op;
    Wrapper<float> a(1.25f), b(1.24f);
    Wrapper<float> result = op(a,b);
    EXPECT_EQ(result.value, 2.49f);
}

TEST_F(CalculateTest, BinaryOpBool) {
    BinaryOp<bool> op;
    Wrapper<bool> a(true), b(false);
    Wrapper<bool> result = op(a, b);
    EXPECT_EQ(result.value, true);
}