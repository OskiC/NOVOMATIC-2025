//
// Created by xoska on 22.04.2025.
//

#ifndef CALCULATE_H
#define CALCULATE_H

#include "binary_op.h"

template <class BinaryOp, class ValueType>
requires IsSupported<ValueType, BinaryOp>
ValueType calculate(int n, ValueType value, const BinaryOp& f) {
    ValueType result = ValueType::identity();
    while (n > 0) {
        if (n % 2 == 1) {
            result = f(result, value);
        }
        value = f(value, value);
        n /= 2;
    }
    return result;
}

#endif //CALCULATE_H
