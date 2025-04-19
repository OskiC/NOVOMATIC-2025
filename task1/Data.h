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

constexpr size_t sizeX{7};
constexpr size_t sizeY{3};


template<typename T>
using Array2D = std::array<std::array<T, sizeX>, sizeY>;

template<typename T>
using CompressedData = std::vector<Data<T>>;

template<typename T>
using CompressedDataArray = std::optional<std::vector<CompressedData<T>>>;

template<typename T>
CompressedDataArray<T> compressedData(const Array2D<T>& input) {
    CompressedDataArray<T> result = std::vector<CompressedData<T>>{};


    for (size_t i = 0; i < sizeY; i++) {
        T value = input[i][0];
        uint8_t count = 1;

        CompressedData<T> compressedDataRow;

        for (size_t j = 1; j < sizeX; j++) {
            if (input[i][j] == value) {
                count++;
            }
            else {
                Data<T> data = {value, count};
                compressedDataRow.push_back(data);
                value = input[i][j];
                count = 1;
            }
        }
        Data<T> data = {value, count};
        compressedDataRow.push_back(data);

        result->push_back(compressedDataRow);
    }

    size_t compressedSize = 0;
    for (const auto& row : *result) {
        compressedSize += row.size();
    }

    if (compressedSize >= sizeX * sizeY) {
        return std::nullopt;
    }
    return result;
}

#endif //DATA_H
