//
// Created by xoska on 22.04.2025.
//

#ifndef WRAPPER_H
#define WRAPPER_H

#include <iostream>
#include <vector>

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
        return Wrapper(value ^ other.value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Wrapper& obj) {
        return os << std::boolalpha << obj.value;
    }
};

template<>
class Wrapper<char> {
public:
    std::vector<char> value;

    Wrapper(char c) : value{c}{}
    Wrapper(const std::vector<char>& v) : value(v){}

    static Wrapper identity() {
        return Wrapper(std::vector<char>{});
    }

    Wrapper operator+(const Wrapper& other) const {
        std::vector<char> result = value;
        result.insert(result.end(), other.value.begin(), other.value.end());
        return Wrapper(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Wrapper& obj) {
        for (char c : obj.value) {
            os << c;
        }
        return os;
    }
};
#endif //WRAPPER_H
