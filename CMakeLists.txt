cmake_minimum_required(VERSION 3.24)

add_compile_definitions(COMPAT_DLLEXPORT)
add_compile_definitions(COMPAT_MSVC99)
add_compile_definitions(COMPAT_MSVC99_TYPESFUNC)

project(types_test C)

set(CMAKE_C_STANDARD 99)

add_executable(types_test types_test.c)
