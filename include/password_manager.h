/******************************************************************************
 * Project: Password Manager - Console App
 * File: password_manager.h
 * Description:
 *   Declares the `PasswordManager` class, responsible for managing passwords.
 *   This class provides functionality to:
 *     - Store and retrieve passwords securely.
 *     - Encrypt and decrypt passwords using an `IEncryption` strategy.
 *     - Load and save password data from a file.
 *     - Track modifications to determine if saving is needed.
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
#include "IEncryption.h"
#include <string>
#include <unordered_map>
#include <filesystem>

/**
 * @class PasswordManager
 * @brief Manages the storage, retrieval, and modification of user passwords.
 * 
 * This class provides functionality to add, delete, view, and save passwords
 * using an encryption interface. It ensures that any modifications trigger
 * a flag (`m_HasUpdated`) indicating unsaved changes.
 */
class PasswordManager {
private:

    /**
     * @brief Stores application-password pairs.
     * 
     * This unordered map holds the credentials where:
     * - The **key** (`std::string`) represents the application or website name.
     * - The **value** (`std::string`) is the associated password.
     * 
     * The data is loaded from a file at initialization and updated as the user
     * adds or removes passwords.
     */
    std::unordered_map<std::string, std::string> m_DataMap;

    /**
     * @brief Tracks whether any modifications have been made.
     * 
     * - **`true`**: Changes have been made to `m_DataMap`, and they should be saved.
     * - **`false`**: No changes were made, so saving is unnecessary.
     * 
     * This flag ensures that data is only written to a file when needed.
     */
    bool m_HasUpdated;

public:
    PasswordManager() = delete; // don't allow default constructor as the following constructors are required

    /**
     * @brief Constructs a PasswordManager with preloaded data.
     * 
     * @param data Unordered map containing app-password pairs.
     * @param encryption Pointer to an encryption strategy implementing `IEncryption`.
     */
    PasswordManager(std::unordered_map<std::string, std::string>&& data);

    /**
     * @brief Adds or updates a password for a given application.
     * 
     * @param app The application or website name.
     * @param pass The password associated with the app.
     */
    void AddPassword(std::string& app, std::string& pass);

    /**
     * @brief Deletes a password entry if it exists.
     * 
     * @param app The application or website name whose password should be deleted.
     * 
     * @note If the entry does not exist, an error message is displayed.
     */
    void DeletePassword(std::string& app);

    /**
     * @brief Displays all saved passwords.
     * 
     * @note If no passwords exist, an appropriate message is displayed.
     */
    void ViewPasswords();

    /**
     * @brief Saves password data to a file if changes have been made.
     * 
     * @param filePath Path to the file where password data will be stored.
     * @return `true` if data was successfully saved, `false` otherwise.
     * 
     * @note If no modifications were made, saving is skipped.
     */
    bool CommitData(std::filesystem::path& filePath, const IEncryption& encryption);

};