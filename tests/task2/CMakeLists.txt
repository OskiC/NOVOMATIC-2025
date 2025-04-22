cmake_minimum_required(VERSION 3.28)
project(task2_tests)

set(CMAKE_CXX_STANDARD 17)

set(MAIN_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../task2")

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

add_executable(task2_tests test_collision.cpp
        ${MAIN_PROJECT_DIR}/core/engine.cpp
        ${MAIN_PROJECT_DIR}/entities/triangle.cpp
)

target_include_directories(task2_tests PRIVATE
        ${MAIN_PROJECT_DIR}/core
        ${MAIN_PROJECT_DIR}/entities
        ${MAIN_PROJECT_DIR}/helper
)

target_link_libraries(task2_tests PRIVATE
        sfml-graphics
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(task2_tests)