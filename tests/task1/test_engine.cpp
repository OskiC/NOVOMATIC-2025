//
// Created by xoska on 23.04.2025.
//
#include <gtest/gtest.h>
#include "engine.h"

class EngineTest : public ::testing::Test {
protected:
    void SetUp() override {
        filename = "test_file.txt";
        std::ofstream file(filename);
        file << "query1\nquery2\nquery3\nquery1\n";
        file.close();

        engine = oc::Engine(filename);
    }

    void TearDown() override {
        std::remove(filename.c_str());
    }

    std::string filename;
    oc::Engine engine;
};