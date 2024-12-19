# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.16)

# Project name and C++ standard
project(EXECUTABLE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set GCC as the compiler (optional)
if(NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER g++)
endif()

# Include directories
include_directories(include)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add the executable target
add_executable(EXECUTABLE src/main.cpp)

# Link SFML libraries
target_link_libraries(EXECUTABLE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

# Copy assets directory to the build directory
add_custom_command(
    TARGET EXECUTABLE POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:EXECUTABLE>/assets
)

# Optional: Enable more compiler warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(EXECUTABLE PRIVATE -Wall -Wextra -pedantic)
endif()
