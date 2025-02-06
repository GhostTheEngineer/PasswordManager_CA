/******************************************************************************
 * Project: Password Manager - Console App
 * File: logger.cpp
 * Description:
 *   Implements the `Logger` class, which provides a simple logging utility.
 *   The logger supports:
 *     - Logging informational messages with `[INFO]` prefix.
 *     - Logging warning messages with `[WARNING]` prefix.
 *     - Logging error messages with `[ERROR]` prefix.
 *     - Automatic timestamp generation for all logs.
 *
 * Copyright © 2025 Ghost - Two Byte Tech. All Rights Reserved.
 *
 * This source code is licensed under the MIT License. For more details, see
 * the LICENSE file in the root directory of this project.
 *
 * Version: v1.1.0
 * Author: Ghost
 * Created On: 02-06-2025
 * Last Modified: 02-06-2025
 *****************************************************************************/

#include "logger.h"
#include <chrono>
#include <iomanip>
#include <sstream>

void Logger::Info(const char* message, bool lineBreak) {
    if (lineBreak) std::clog << "[INFO] " << GetTimestamp() << " " << message << std::endl;
    else std::clog << "[INFO] " << GetTimestamp() << " - " << message;
}

void Logger::Warning(const char* message, bool lineBreak) {
    if (lineBreak) std::clog << "[WARNING] " << GetTimestamp() << " " << message << std::endl;
    else std::clog << "[WARNING] " << GetTimestamp() << " - " << message;
}

void Logger::Error(const char* message, bool lineBreak) {
    if (lineBreak) std::cerr << "[ERROR] " << GetTimestamp() << " " << message << std::endl;
    else std::cerr << "[ERROR] " << GetTimestamp() << " - " << message;
}

std::string Logger::GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto timeT = std::chrono::system_clock::to_time_t(now);
    std::tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &timeT);
#else
    localtime_r(&timeT, &localTime);
#endif
    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
