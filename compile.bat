@echo off
setlocal

:: Require build flag
if not "%1"=="Release" if not "%1"=="Debug" (
    echo Usage: build.bat Release or Debug
    exit /b 1
)
set BUILD_TYPE=%1
set BUILD_DIR=out/%BUILD_TYPE%

:: Create directory and change to it
if not exist %BUILD_DIR% (
    echo creating build directory..
    mkdir "%BUILD_DIR%"
)

:: change directory to build folder
cd /d "%BUILD_DIR%"

:: Compile based on flag
if %BUILD_TYPE% == Debug (
    echo compiling in debug mode..
    g++ -DDEBUG=1 ../../src/*.cpp -std=c++17 -I../../include -o password_manager
) else (
    echo compiling in release mode..
    g++ ../../src/*.cpp -std=c++17 -I../../include -o password_manager
)
