/******************************************************************************
 * Project: Password Manager - Console App
 * File: password_manager.cpp
 * Description:
 *   Defines the `PasswordManager` class, responsible for managing passwords.
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

#include "password_manager.h"
#include "custom_terminal.h"
#include "custom_io.h"

PasswordManager::PasswordManager(std::unordered_map<std::string, std::string>&& data) 
    : m_HasUpdated(false) {

    m_DataMap = std::move(data); // transfer ownership of rvlaue to class member
}

void PasswordManager::AddPassword(std::string& app, std::string& pass) {
    if (app.empty()) {
        CustomTerminal::AddMessageToBuffer("Password requires an app name, try again!", 2);
        return;
    }

    if (!m_HasUpdated) m_HasUpdated = true;

    m_DataMap[app] = pass;

    CustomTerminal::AddMessageToBuffer("Password added successfully!", 2);
}

void PasswordManager::DeletePassword(std::string& app) {
    if (!m_HasUpdated) m_HasUpdated = true;

    if (m_DataMap.erase(app)) { // erase data from map 
        CustomTerminal::AddMessageToBuffer("Password deleted successfully!", 2);
        return;
    } 
    CustomTerminal::AddMessageToBuffer("Could not find entry.", 2);
}

void PasswordManager::ViewPasswords() {
    CustomTerminal::AddMessageToBuffer("Saved Passwords:", 1);
    if (!m_DataMap.empty()) {
        for (const auto& [app, pass] : m_DataMap) {
            CustomTerminal::AddMessageToBuffer(("  - App: " + app + ", Password: " + pass), 1);
        }
    }
    else CustomTerminal::AddMessageToBuffer(("  No passwords saved!"), 1);
    CustomTerminal::AddMessageToBuffer("",1); // space
}

bool PasswordManager::CommitData(std::filesystem::path& filePath, const IEncryption& encryption) {
    if (m_HasUpdated) {
        if (!CustomIO::SaveToFile(m_DataMap, filePath, encryption)) {
            CustomTerminal::AddMessageToBuffer("There was a problem while attempting to save data to file.", 2);
        }
        else return true;
    }
    CustomTerminal::AddMessageToBuffer("No changes were made, did not save to file.", 2);
    return false;
}
