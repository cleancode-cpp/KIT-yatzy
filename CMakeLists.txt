cmake_minimum_required(VERSION 3.15.0)
project(MyApp)
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
add_library(mylib)
target_sources(mylib
    PRIVATE
        MyClass.cc
    PUBLIC
        MyClass.h
)
set_target_properties(mylib PROPERTIES
    COMPILE_FLAGS "${cxx_strict}"
)

# text tests
add_executable(app)
target_sources(app
    PRIVATE
        MyApp.cc
)
set_target_properties(app PROPERTIES
    COMPILE_FLAGS "${cxx_strict}"
)
target_link_libraries(app
    PRIVATE
        mylib
)

# unit tests
add_executable(my_tests)
target_sources(my_tests
    PRIVATE
        MyUnitTests.cc
)
set_target_properties(my_tests PROPERTIES
    COMPILE_FLAGS "${cxx_strict}"
)
target_link_libraries(my_tests
    PRIVATE
        mylib
        gtest
        gtest_main
)
add_test(my_tests my_tests)
