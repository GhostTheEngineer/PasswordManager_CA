#!/bin/bash

# Ensure script stops on errors
set -e

# Require build flag
if [[ "$1" != "Release" && "$1" != "Debug" ]]; then
    echo "Usage: build.sh Release or Debug"
    exit 1
fi

BUILD_TYPE="$1"
BUILD_DIR="out/$BUILD_TYPE"

# Create build directory if it does not exist
if [[ ! -d "$BUILD_DIR" ]]; then
    echo "Creating build directory..."
    mkdir -p "$BUILD_DIR"
fi

# Change directory to build folder
cd "$BUILD_DIR"

# Run CMake configuration if not already configured
if [[ ! -f "CMakeCache.txt" ]]; then
    echo "Configuring CMake..."
    cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" ../..
fi

# Build the project
echo "Building in $BUILD_TYPE mode..."
cmake --build . --config "$BUILD_TYPE"
