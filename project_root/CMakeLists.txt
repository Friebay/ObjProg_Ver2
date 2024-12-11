# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure consistent runtime libraries
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()

# Set build type to Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

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