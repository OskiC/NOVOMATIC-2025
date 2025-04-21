#include <gtest/gtest.h>
#include "Data.h"

TEST(CompressionTest, CompressesExampleCorrectly) {
    Array2D<int, 3, 7> input = {{
        {0, 0, 0, 1, 1, 2, 3},
        {0, 0, 4, 4, 4, 2, 2},
        {2, 2, 2, 2, 2, 1, 2}
    }};

    auto result = compressedData(input);

    ASSERT_TRUE(result.has_value()) << "Expected a valid compressed result";

    const auto& actualData = *result;
    ASSERT_EQ(actualData.size(), 3) << "Row count mismatch";

    std::vector<std::vector<std::pair<int, uint8_t>>> expected = {
        {{0, 3}, {1, 2}, {2, 1}, {3, 1}},
        {{0, 2}, {4, 3}, {2, 2}},
        {{2, 5}, {1, 1}, {2, 1}}
    };

    for (size_t i = 0; i < expected.size(); ++i) {
        const auto& expectedRow = expected[i];
        const auto& actualRow = actualData[i];
        ASSERT_EQ(actualRow.size(), expectedRow.size()) << "Row " << i << " size mismatch";

        for (size_t j = 0; j < expectedRow.size(); ++j) {
            EXPECT_EQ(actualRow[j].value, expectedRow[j].first) << "Mismatch at [" << i << "][" << j << "] - value";
            EXPECT_EQ(actualRow[j].count, expectedRow[j].second) << "Mismatch at [" << i << "][" << j << "] - count";
        }
    }
}

TEST(CompressionTest, NoCompressionPossibleReturnsNullopt) {
    Array2D<int, 3, 7> input = {{
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21}
    }};

    auto result = compressedData(input);
    EXPECT_FALSE(result.has_value()) << "Expected no compression result";
}

TEST(CompressionTest, SingleValueRowsCompressCorrectly) {
    Array2D<int, 3, 7> input = {{
        {1, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3, 3, 3}
    }};

    auto result = compressedData(input);

    ASSERT_TRUE(result.has_value()) << "Expected a valid compressed result";

    const auto& actualData = *result;
    ASSERT_EQ(actualData.size(), 3) << "Row count mismatch";

    std::vector<std::vector<std::pair<int, uint8_t>>> expected = {
        {{1, 7}},
        {{2, 7}},
        {{3, 7}}
    };

    for (size_t i = 0; i < expected.size(); ++i) {
        const auto& expectedRow = expected[i];
        const auto& actualRow = actualData[i];
        ASSERT_EQ(actualRow.size(), expectedRow.size()) << "Row " << i << " size mismatch";

        for (size_t j = 0; j < expectedRow.size(); ++j) {
            EXPECT_EQ(actualRow[j].value, expectedRow[j].first) << "Mismatch at [" << i << "][" << j << "] - value";
            EXPECT_EQ(actualRow[j].count, expectedRow[j].second) << "Mismatch at [" << i << "][" << j << "] - count";
        }
    }
}

TEST(CompressionTest, AlternatingPatternNoCompression) {
    Array2D<int, 3, 7> input = {{
        {1, 2, 1, 2, 1, 2, 1},
        {2, 1, 2, 1, 2, 1, 2},
        {1, 2, 1, 2, 1, 2, 1}
    }};

    auto result = compressedData(input);
    EXPECT_FALSE(result.has_value()) << "Expected no compression result";
}
