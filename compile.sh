#!/bin/bash

BUILD_TYPE=$1
BUILD_DIR="out/$BUILD_TYPE"

# Create directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir -p "$BUILD_DIR"
fi

# Change to build directory
cd "$BUILD_DIR" || exit

# Compile based on the build type
if [ "$BUILD_TYPE" == "Debug" ]; then
    echo "Compiling in debug mode..."
    g++ -DDEBUG=1 ../../src/*.cpp -std=c++17 -I../../include -o password_manager
else
    echo "Compiling in release mode..."
    g++ ../../src/*.cpp -std=c++17 -I../../include -o password_manager
fi
