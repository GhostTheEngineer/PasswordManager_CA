/******************************************************************************
 * Project: Password Manager - Console App
 * File: HexE.h
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

#pragma once
#include "IEncryption.h"
#include <string>

/**
 * @class HEXEncryption
 * @brief A hexadecimal-based encryption class implementing the IEncryption interface.
 *
 * The `HEXEncryption` class provides an implementation of the `IEncryption` interface, 
 * encoding plaintext strings into a hexadecimal format and decoding them back. This allows 
 * simple, readable obfuscation of stored data while adhering to a structured encryption interface.
 */
class HEXEncryption : public IEncryption {
public:
    HEXEncryption() = default;
    ~HEXEncryption() override = default;

    /**
     * @brief Encrypts a given string by converting it to a hexadecimal representation.
     * 
     * Each character in the input string is represented as two hexadecimal digits.
     * 
     * @param input The plaintext string to be encrypted.
     * @return A hexadecimal-encoded string.
     */
    std::string encrypt(const std::string& input) const override;

    /**
     * @brief Decrypts a hexadecimal-encoded string back to its original form.
     * 
     * The function expects a valid hex-encoded string where each pair of hex digits represents a character.
     * 
     * @param input The hexadecimal string to be decrypted.
     * @return The original plaintext string.
     */
    std::string decrypt(const std::string& input) const override;
};
