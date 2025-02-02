/******************************************************************************
 * Project: Password Manager - Console App
 * File: custom_terminal.cpp
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

#include "../include/custom_terminal.h"
#include <cstdlib> 

// Static buffer to hold messages for printing.
std::vector<std::string> CustomTerminal::BUFFER({}); 

void CustomTerminal::ClearTerminal() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux and macOS
#endif
}

void CustomTerminal::PrintAndClearBuffer() {
    for (const auto& message : BUFFER) {
        std::cout << message;
    }
    BUFFER.clear();
}

void CustomTerminal::AddMessageToBuffer(std::string&& message, int lineBreakCount) {
    if (lineBreakCount > 0) {
        message.append(lineBreakCount, '\n');  // Modify message directly
    }
    // BUFFER.reserve(BUFFER.size() + 1);  // Prevents unnecessary reallocations - UPDATE: not needed since the buffer is cleared each iteration and is limited with growth
    BUFFER.push_back(std::move(message));
}