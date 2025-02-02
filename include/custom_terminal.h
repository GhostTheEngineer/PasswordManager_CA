/******************************************************************************
 * Project: Password Manager - Console App
 * File: custom_terminal.h
 * Description:
 *   A utilities class for custom terminal logic.
 *
 * Copyright © 2025 Ghost - Two Byte Tech. All Rights Reserved.
 *
 * This source code is licensed under the MIT License. For more details, see
 * the LICENSE file in the root directory of this project.
 *
 * Version: v1.0
 * Author: Ghost
 * Created On: 1-28-2025
 * Last Modified: 1-29-2025
 *****************************************************************************/

#pragma once
#include <iostream>
#include <vector>

/**
 * @class CustomTerminal
 * @brief Provides utility functions for terminal management, including clearing the screen and handling message buffers.
 * 
 * The CustomTerminal class is designed to manage terminal-related operations in a cross-platform manner.
 * It includes functionality for clearing the terminal and maintaining a buffer of messages to be printed.
 */
class CustomTerminal {
public:
    /**
     * @brief Static buffer to hold messages for printing.
     */
    static std::vector<std::string> BUFFER;

    /**
     * @brief Clears the terminal screen in a cross-platform way.
     * 
     * - On Windows, it uses the `cls` command.
     * - On Linux and macOS, it uses the `clear` command.
     */
    static void ClearTerminal();

    /**
     * @brief Prints all messages in the buffer and then clears the buffer.
     * 
     * Each message in the buffer is printed in the order it was added.
     * After printing, the buffer is cleared.
     */
    static void PrintAndClearBuffer();

    /**
     * @brief Adds a message to the buffer, optionally appending line breaks.
     * 
     * @param message The message to add to the buffer.
     * @param lineBreakCount The number of line breaks to append to the message. Defaults to 0.
     */
    static void AddMessageToBuffer(std::string&& message, int lineBreakCount = 0);
};


