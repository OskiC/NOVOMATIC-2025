cmake_minimum_required(VERSION 3.28)
project(task3)

set(CMAKE_CXX_STANDARD 20)

add_executable(task3 main.cpp
        Wrapper.h
        binary_op.h
        calculate.h
)