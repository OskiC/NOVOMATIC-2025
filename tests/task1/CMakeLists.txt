add_executable(task1_tests test_compression.cpp)

target_include_directories(task1_tests PRIVATE
        ${PROJECT_SOURCE_DIR}/task1
)

target_link_libraries(task1_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(task1_tests)