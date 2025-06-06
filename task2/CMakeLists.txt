cmake_minimum_required(VERSION 3.28)
project(task2)

set(CMAKE_CXX_STANDARD 17)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(task2 main.cpp
        core/engine.cpp
        core/engine.h
        entities/triangle.cpp
        entities/triangle.h
        helper/vec2.h
        helper/utils.h
        helper/config.h
)

add_custom_command(
        TARGET task2
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        $<TARGET_FILE_DIR:task2>/fonts
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/task2/fonts/OptimusPrinceps.ttf
        $<TARGET_FILE_DIR:task2>/fonts
        COMMENT "Copying font file to build/fonts directory"
)

target_link_libraries(task2 PRIVATE sfml-graphics)
target_compile_features(task2 PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET task2
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:task2>
            VERBATIM)
endif()

install(TARGETS task2)