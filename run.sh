#!/bin/bash

BUILD_TYPE=${1:-"Debug"}  # Default to Debug if no argument is provided
EXECUTABLE="out/$BUILD_TYPE/password_manager"

if [ -f "$EXECUTABLE" ]; then
    echo "Running Password Manager..."
    "$EXECUTABLE"
else
    echo "Error: Executable not found. Did you compile the project?"
    exit 1
fi
