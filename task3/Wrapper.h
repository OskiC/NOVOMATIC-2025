//
// Created by xoska on 22.04.2025.
//

#ifndef WRAPPER_H
#define WRAPPER_H

#include <iostream>

template <typename T>
class Wrapper {
public:
    T value;

    Wrapper(T v) : value(v) {}

    static Wrapper identity() {
        return Wrapper(T{});
    }

    Wrapper operator+(const Wrapper& other) const {
        return Wrapper(value + other.value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Wrapper& obj) {
        return os << obj.value;
    }
};

template<>
class Wrapper<bool> {
public:
    bool value;

    Wrapper(bool v) : value(v){}

    static Wrapper identity() {
        return Wrapper(bool{});
    }

    Wrapper operator+(const Wrapper& other) const {
        return Wrapper(value || other.value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Wrapper& obj) {
        return os << std::boolalpha << obj.value;
    }
};

#endif //WRAPPER_H
