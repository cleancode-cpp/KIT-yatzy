cmake_minimum_required(VERSION 3.15.0)
project(YatzyApp)
enable_testing()

set (CMAKE_CXX_STANDARD 11)
set (gtest_force_shared_crt ON CACHE BOOL "MSVC defaults to shared CRT" FORCE)

add_subdirectory(third_party/googletest/googletest)
target_compile_definitions(gtest
    PUBLIC
        GTEST_LANG_CXX11
        GTEST_HAS_TR1_TUPLE=0
)

# domain library
add_library(yatzylib)
target_sources(yatzylib
    PRIVATE
        YatzyScore.cc
    PUBLIC
        YatzyScore.h
)
set_target_properties(yatzylib PROPERTIES
    COMPILE_FLAGS "${cxx_strict}"
)

# app
add_executable(yatzy)
target_sources(yatzy
    PRIVATE
        YatzyApp.cc
)
set_target_properties(yatzy PROPERTIES
    COMPILE_FLAGS "${cxx_strict}"
)
target_link_libraries(yatzy
    PRIVATE
        yatzylib
)

# unit tests
add_executable(yatzy_tests)
target_sources(yatzy_tests
    PRIVATE
        YatzyScoreTests.cc
)
set_target_properties(yatzy_tests PROPERTIES
    COMPILE_FLAGS "${cxx_strict}"
)
target_link_libraries(yatzy_tests
    PRIVATE
        yatzylib
        gtest
        gtest_main
)
add_test(yatzy_tests yatzy_tests)
