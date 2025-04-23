cmake_minimum_required(VERSION 3.28)
project(task3_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(task3_tests test_wrapper.cpp
        test_binaryop.cpp
        test_calculate.cpp)

target_include_directories(task3_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../task3
)

target_link_libraries(task3_tests PRIVATE
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(task3_tests)