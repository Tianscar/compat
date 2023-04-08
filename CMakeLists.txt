cmake_minimum_required(VERSION 3.0)

project(types_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_BUILDING_DLL)
    add_compile_definitions(COMPAT_TYPES)
    add_compile_definitions(COMPAT_INTTYPES_FUNCTIONS)
    add_executable(types_test compat/msvc/inttypes.c types_test.c)
else ()
    add_executable(types_test types_test.c)
endif ()

project(regex_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_BUILDING_DLL)
    add_compile_definitions(COMPAT_TYPES)
    file(GLOB REGEX_FILES compat/gnuwin32/regex/*.*)
    add_library(gnurx SHARED ${REGEX_FILES})
    add_compile_definitions(COMPAT_INTTYPES_FUNCTIONS)
    add_executable(regex_test compat/msvc/inttypes.c regex_test.c)
else ()
    add_executable(regex_test regex_test.c)
endif ()
if (WIN32)
    target_link_libraries(regex_test gnurx)
endif ()
