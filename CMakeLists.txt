cmake_minimum_required(VERSION 3.24)

if (WIN32)
add_compile_definitions(COMPAT_DLLEXPORT)
endif()

project(types_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_MSVC99)
    add_compile_definitions(COMPAT_MSVC99_TYPESFUNC)
    add_executable(types_test compat/msvc/inttypes.c types_test.c)
else()
    add_executable(types_test types_test.c)
endif()
