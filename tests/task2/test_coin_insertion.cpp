//
// Created by xoska on 21.04.2025.
//
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "entity/state_coin_insertion.h"
#include "entity/exit_override.h"
#include "entity/machine_context.h"

using namespace oc;

class CoinInsertionTest : public ::testing::Test {
protected:
    std::streambuf* origCin;
    std::streambuf* origCout;
    std::istringstream inputBuffer;
    std::ostringstream outputBuffer;

    Context* context;

    void SetUp() override {
        origCin = std::cin.rdbuf();
        origCout = std::cout.rdbuf();
        std::cin.rdbuf(inputBuffer.rdbuf());
        std::cout.rdbuf(outputBuffer.rdbuf());

        context = new Context(new MachineStateCoinInsertion());
    }

    void TearDown() override {
        std::cin.rdbuf(origCin);
        std::cout.rdbuf(origCout);
        delete context;
    }

    void SetInput(const std::string& input) {
        inputBuffer.str(input);
        inputBuffer.clear();
    }

    std::string GetOutput() {
        return outputBuffer.str();
    }

};

TEST_F(CoinInsertionTest, InsertCoinsAndCheckBalance) {
    SetInput("2\n3\n0\n");  // Insert coins 2, then 3, and attempt to buy a ticket

    context->InsertCoin();

    std::string output = GetOutput();

    // Check the balance after inserting coins
    EXPECT_NE(output.find("Balance: 2"), std::string::npos);  // After first coin
    EXPECT_NE(output.find("Balance: 5"), std::string::npos);  // After second coin

    EXPECT_EQ(output.find("Please insert some coins first"), std::string::npos);  // No need for this message in the test
}

TEST_F(CoinInsertionTest, TryToBuyTicketWithoutBalance) {
    SetInput("0\n-2\n");  // Try to buy a ticket with no coins inserted

    oc::SetExitHandler([](int) {
        throw std::runtime_error("exit intercepted");
    });

    try {
        context->InsertCoin();
    } catch (const std::runtime_error&) {

    }

    std::string output = GetOutput();

    EXPECT_NE(output.find("Please insert some coins first"), std::string::npos);
}
