cmake_minimum_required(VERSION 3.10)

# Project name
project(PasswordManager CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find all source files
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add executable
add_executable(password_manager ${SRC_FILES})

# Debug mode definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(password_manager PRIVATE DEBUG=1)
endif()
