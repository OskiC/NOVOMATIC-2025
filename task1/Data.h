//
// Created by xoska on 19.04.2025.
//

#ifndef DATA_H
#define DATA_H
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>
#include <array>

template<typename T> struct Data {
    T value;

    uint8_t count;
};

constexpr size_t sizeX{32};
constexpr size_t sizeY{16};


template<typename T, size_t Rows, size_t Cols>
using Array2D = std::array<std::array<T, Cols>, Rows>;

template<typename T>
using CompressedData = std::vector<Data<T>>;

template<typename T>
using CompressedDataArray = std::optional<std::vector<CompressedData<T>>>;

template<typename T, size_t Rows, size_t Cols>
CompressedDataArray<T> compressedData(const Array2D<T, Rows, Cols>& input) {
    CompressedDataArray<T> result = std::vector<CompressedData<T>>{};


    for (size_t i = 0; i < Rows; i++) {
        T value = input[i][0];
        uint8_t count = 1;

        CompressedData<T> compressedDataRow;

        for (size_t j = 1; j < Cols; j++) {
            if (input[i][j] == value) {
                count++;
            }
            else {
                compressedDataRow.push_back({value, count});
                value = input[i][j];
                count = 1;
            }
        }
        compressedDataRow.push_back({value, count});

        result->push_back(compressedDataRow);
    }

    size_t compressedSize = 0;
    for (const auto& row : *result) {
        compressedSize += row.size();
    }

    if (compressedSize >= Rows * Cols) {
        return std::nullopt;
    }
    return result;
}

#endif //DATA_H
