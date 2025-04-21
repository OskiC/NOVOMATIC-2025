#include "Data.h"

int main() {
    Array2D<int, 3, 7> input = {
        {
            {0, 0, 0, 1, 1, 2, 3},
           {0, 0, 4, 4, 4, 2, 2},
           {2, 2, 2, 2, 2, 1, 2}
        }
    };
    if (auto result = compressedData(input)) {
        std::cout << "{";
        for (size_t i = 0; i < result->size(); ++i) {
            for (size_t j = 0; j < (*result)[i].size(); ++j) {
                auto[value, count] = (*result)[i][j];
                std::cout << "{" << value << "," << static_cast<int>(count) << "}";
                if (i != result->size() - 1 || j != (*result)[i].size() - 1)
                    std::cout << ",";
            }
            if (i != result->size() - 1)
                std::cout << "\n";
        }
        std::cout << "}" << std::endl;
    } else {
        std::cout << "Compression not effective.\n";
    }
}