#include "calculate.h"

int main() {
    Wrapper<int> int_val(5);
    std::cout << "int (n=3, value=5): " << calculate(3, int_val, BinaryOp<int>{}) << "\n"; // 15

    return 0;
}