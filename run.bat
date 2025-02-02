@echo off
setlocal

:: Require build flag
if not "%1"=="Release" if not "%1"=="Debug" (
    echo Usage: build.bat Release or Debug
    exit /b 1
)
set BUILD_TYPE=%1
set BUILD_DIR=out/%BUILD_TYPE%

:: You may also just manually open program in your file explorer ./out/password_manager.exe

if exist %BUILD_DIR%/password_manager.exe (
    :: Changing directory first allows the password.txt file to save in the out directory
    cd /d "%BUILD_DIR%" 
    start password_manager.exe
) else (
    echo Could not find .exe file. Please run ./compile in main directory first!
)