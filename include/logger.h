/******************************************************************************
 * Project: Password Manager - Console App
 * File: logger.h
 * Description:
 *   Declares the `Logger` class, which provides a simple logging utility.
 *   This class supports:
 *     - Logging informational messages to `std::clog`.
 *     - Logging warning messages to `std::clog`.
 *     - Logging error messages to `std::cerr`.
 *     - Automatic timestamping of log messages.
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

#pragma once
#include <iostream>

/**
 * @class Logger
 * @brief A simple logging utility using `std::clog` for general logs and `std::cerr` for errors.
 * 
 * This class provides functionality to:
 * - Log informational messages to `std::clog`.
 * - Log error messages to `std::cerr`.
 * - Automatically timestamp messages.
 */
class Logger {
public:
        /**
     * @brief Logs an informational message to `std::clog`.
     * 
     * This function prints an informational message prefixed with `[INFO]`,
     * along with a timestamp. It is primarily used for general application
     * logs that do not indicate errors or warnings.
     * 
     * @param message The message to log.
     * @param lineBreak If `true`, appends a newline (`std::endl`) after the message.
     *                  If `false`, the message is printed on the same line.
     */
    static void Info(const char* message, bool lineBreak = true);

    /**
     * @brief Logs a warning message to `std::clog`.
     * 
     * This function prints a warning message prefixed with `[WARNING]`,
     * along with a timestamp. It is used for situations that are not errors
     * but may require attention.
     * 
     * @param message The warning message to log.
     * @param lineBreak If `true`, appends a newline (`std::endl`) after the message.
     *                  If `false`, the message is printed on the same line.
     */
    static void Warning(const char* message, bool lineBreak = true);

    /**
     * @brief Logs an error message to `std::cerr`.
     * 
     * This function prints an error message prefixed with `[ERROR]`,
     * along with a timestamp. It is used to log critical failures that
     * need immediate attention.
     * 
     * @param message The error message to log.
     * @param lineBreak If `true`, appends a newline (`std::endl`) after the message.
     *                  If `false`, the message is printed on the same line.
     */
    static void Error(const char* message, bool lineBreak = true);

private:
    /**
     * @brief Retrieves the current timestamp as a formatted string.
     * @return A string representation of the current time.
     */
    static std::string GetTimestamp();
};
