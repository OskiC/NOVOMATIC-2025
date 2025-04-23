//
// Created by xoska on 23.04.2025.
//
#define UNIT_TEST
#include <gtest/gtest.h>
#include "engine.h"
#include <stdexcept>

class EngineTest : public ::testing::Test {
protected:
    std::string filename;
    oc::Engine engine;

    EngineTest() : filename("test_file.txt"), engine(filename){}

    void SetUp() override {
        std::ofstream file(filename);
        file << "query1\nquery2\nquery3\nquery1\n";
        file.close();
        engine.load_from_file(filename);
    }

    void TearDown() override {
        std::remove(filename.c_str());
    }

};

TEST_F(EngineTest, LoadFromFileSuccess) {
    EXPECT_EQ(engine.queries_list["query1"], 2);
    EXPECT_EQ(engine.queries_list["query2"], 1);
}

TEST_F(EngineTest, AddQuery) {
    engine.addQuery("query1");
    EXPECT_EQ(engine.queries_list["query1"], 3);

    EXPECT_THROW(engine.queries_list.at("query4"), std::out_of_range);

    engine.addQuery("query4");
    EXPECT_EQ(engine.queries_list["query4"], 1);
}

TEST_F(EngineTest, Ask) {
    engine.addQuery("query1");
    engine.addQuery("query2");

    std::vector<std::string> result = engine.ask("query");
    EXPECT_EQ(result, std::vector<std::string>({"query1", "query2", "query3"}));
}