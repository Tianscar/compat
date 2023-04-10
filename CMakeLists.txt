cmake_minimum_required(VERSION 3.0)

project(defs_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_BUILDING_DLL)
endif ()

add_executable(defs_test defs_test.c)

project(types_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_TYPES)
endif ()

add_executable(types_test types_test.c)

project(regex_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_BUILDING_DLL)
    add_compile_definitions(COMPAT_TYPES)
    if (COMPAT_GNURX)
        file(GLOB GNURX_FILES compat/windows/gnurx/*.c)
        add_library(gnurx SHARED ${GNURX_FILES})
        add_executable(regex_test regex_test.c)
    else ()
        file(GLOB REGEX_FILES compat/windows/regex/*.c)
        add_executable(regex_test ${REGEX_FILES} regex_test.c)
    endif ()
else ()
    add_executable(regex_test regex_test.c)
endif ()
if (WIN32)
    if (COMPAT_GNURX)
        target_link_libraries(regex_test gnurx)
    endif()
endif ()

project(threads_test C)

set(CMAKE_C_STANDARD 99)

if (WIN32)
    add_compile_definitions(COMPAT_BUILDING_DLL)
    add_compile_definitions(COMPAT_TYPES)
    add_executable(threads_test compat/windows/threads/threads.c threads_test.c)
else ()
    add_executable(threads_test threads_test.c)
endif ()
