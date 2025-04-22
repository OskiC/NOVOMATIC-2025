//
// Created by xoska on 22.04.2025.
//

#ifndef BINARY_OP_H
#define BINARY_OP_H

#include <concepts>
#include "Wrapper.h"

template <typename T>
struct BinaryOp {
    Wrapper<T> operator()(const Wrapper<T>& a, const Wrapper<T>& b) const {
        return a + b;
    }
};

template <class T, class Op>
concept IsSupported = requires(T first, T second, Op operation) {
    { operation(first, second) } -> std::convertible_to<T>;
    { T::identity() } -> std::convertible_to<T>;
};

#endif //BINARY_OP_H
