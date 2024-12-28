cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ObjProg_Ver2 VERSION 2.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure consistent runtime libraries
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd /W4")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD /W4")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -Wall -Wextra -pedantic")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -Wall -Wextra -pedantic")
endif()

# Set build type to Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add include directories
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/Vec_funkcijos.cpp
    src/Vec_funkcijos_papildomos.cpp
    src/Vec_failo_apdorojimas.cpp
    src/Vec_generuoti_failus.cpp
    src/List_funkcijos.cpp
    src/List_failo_apdorojimas.cpp
    src/studentas.cpp
    src/list_studentas.cpp
    src/human.cpp 
)

# Create executable
add_executable(program ${SOURCES})

# Installation rules
install(TARGETS program DESTINATION bin)

# Enable testing
enable_testing()

# Add Catch2 testing
add_executable(tests
    tests/test_main.cpp
    tests/test_vec_funkcijos.cpp
    tests/test_list_funkcijos.cpp
    tests/test_studentas.cpp
    src/Vec_funkcijos.cpp
    src/Vec_funkcijos_papildomos.cpp
    src/Vec_failo_apdorojimas.cpp
    src/Vec_generuoti_failus.cpp
    src/List_funkcijos.cpp
    src/List_failo_apdorojimas.cpp
    src/studentas.cpp
    src/list_studentas.cpp
    src/human.cpp
)
target_include_directories(tests PRIVATE include)
add_test(NAME Catch2Tests COMMAND tests)