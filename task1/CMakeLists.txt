cmake_minimum_required(VERSION 3.28)
project(task1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(task1 main.cpp
        engine.cpp
        engine.h
)