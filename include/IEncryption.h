/******************************************************************************
 * Project: Password Manager - Console App
 * File: IEncryption.h
 * Description:
 *   A interface that allows encryption modules to define their own Encrypt and Decrypt logic.
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
#include <string>

/**
 * @class IEncryption
 * @brief Interface for encryption and decryption operations.
 * 
 * The IEncryption interface defines a contract for implementing encryption and decryption functionality.
 * Any class that inherits from this interface must provide implementations for both `Encrypt` and `Decrypt` methods.
 * This interface is designed to allow flexible and consistent encryption strategies, such as HEX-based encryption,
 * AES encryption, or other algorithms, to be used interchangeably.
 */
class IEncryption {
public:
    /**
     * @brief Encrypts the given input string.
     * 
     * This method is intended to be overridden by derived classes to provide a specific encryption implementation.
     * 
     * @param input The plaintext string to be encrypted.
     * @return The encrypted string.
     */
    virtual std::string encrypt(const std::string& input) const = 0;

    /**
     * @brief Decrypts the given input string.
     * 
     * This method is intended to be overridden by derived classes to provide a specific decryption implementation.
     * 
     * @param input The encrypted string to be decrypted.
     * @return The decrypted string.
     */
    virtual std::string decrypt(const std::string& input) const = 0;

    /**
     * @brief Virtual destructor for the interface.
     * 
     * Ensures proper cleanup of derived class objects through a base class pointer.
     */
    virtual ~IEncryption() = default;
};