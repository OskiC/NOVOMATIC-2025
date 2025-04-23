cmake_minimum_required(VERSION 3.28)
project(task1_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(task1_tests
        test_engine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../task1/engine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../task1/engine.h
)

target_compile_definitions(task1_tests PRIVATE UNIT_TEST)

target_include_directories(task1_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../task1
)

target_link_libraries(task1_tests PRIVATE
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(task1_tests)