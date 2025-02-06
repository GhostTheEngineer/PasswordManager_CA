@echo off
setlocal

:: Require build flag
if not "%1"=="Release" if not "%1"=="Debug" (
    echo Usage: build.bat Release or Debug
    exit /b 1
)
set BUILD_TYPE=%1
set BUILD_DIR=out/%BUILD_TYPE%

:: Create build directory if it does not exist
if not exist %BUILD_DIR% (
    echo Creating build directory..
    mkdir "%BUILD_DIR%"
)

:: Change directory to build folder
cd /d "%BUILD_DIR%"

:: Run CMake
if not exist CMakeCache.txt (
    echo Configuring CMake...
    cmake -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ../..
)

:: Build the project
echo Building in %BUILD_TYPE% mode...
cmake --build . --config %BUILD_TYPE%
