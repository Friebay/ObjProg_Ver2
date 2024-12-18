# Ensure consistent runtime libraries
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
    
    # Configure manifest for admin rights
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()


# Set build type to Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# Embed manifest file to request admin rights
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_custom_command(TARGET program POST_BUILD
        COMMAND mt.exe -manifest "${CMAKE_SOURCE_DIR}/StudPazSkaiciuokle.manifest" -outputresource:"$<TARGET_FILE:program>;1"
    )
endif()

# Installation rules
install(TARGETS program DESTINATION bin)