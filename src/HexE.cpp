/******************************************************************************
 * Project: Password Manager - Console App
 * File: HexE.cpp
 * Description:
 *   An encryption module using the Hex Algorithm. Using the IEncryption interface,
 *   it overloads the Encrypt and Decrypt functions with Hex logic.
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

#include "../include/HexE.h"
#include <vector>

std::string HEXEncryption::encrypt(const std::string& input) const {
    // Optimization: Preallocate memory using a vector to avoid multiple dynamic allocations.
    // Using direct indexing instead of `std::string::append()` improves performance.

    static constexpr char hexDigits[] = "0123456789ABCDEF";

    std::vector<char> buffer(input.size() * 2); // Each byte -> 2 hex chars
    size_t index = 0;

    for (unsigned char c : input) {
        buffer[index++] = hexDigits[c >> 4];  // High nibble
        buffer[index++] = hexDigits[c & 0x0F]; // Low nibble
    }

    return std::string(buffer.begin(), buffer.end());
}

std::string HEXEncryption::decrypt(const std::string& input) const {
    // Optimization: Preallocate buffer to prevent repeated reallocations.
    // Uses direct character-to-hex conversion instead of `std::stoi(std::string(1, c))`, reducing unnecessary object creation.

    std::vector<char> buffer(input.length() / 2);
    size_t index = 0;

    for (size_t i = 0; i < input.length(); i += 2) {
        char high = input[i];
        char low = input[i + 1];
        int highValue = std::isdigit(high) ? high - '0' : std::toupper(high) - 'A' + 10;
        int lowValue  = std::isdigit(low)  ? low - '0'  : std::toupper(low) - 'A' + 10;
        buffer[index++] = (highValue << 4) | lowValue;
    }
    
    return std::string(buffer.begin(), buffer.end());
}
