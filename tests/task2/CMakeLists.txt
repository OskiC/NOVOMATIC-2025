file(GLOB TASK2_SRC_FILES
        ${PROJECT_SOURCE_DIR}/task2/entity/*.cpp
)

add_executable(task2_tests  test_coin_insertion.cpp
        ${TASK2_SRC_FILES}
)

target_compile_definitions(task2_tests PRIVATE UNIT_TESTING)

target_include_directories(task2_tests PRIVATE
        ${PROJECT_SOURCE_DIR}/task2
)

target_link_libraries(task2_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(task2_tests)