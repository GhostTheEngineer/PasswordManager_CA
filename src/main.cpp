/******************************************************************************
 * Project: Password Manager - Console App
 * File: main.cpp
 * Description:
 *   The entry point and main logic to the app.
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

#include <iostream>
#include <algorithm>
#include "../include/custom_io.h"
#include "../include/custom_terminal.h"
#include "../include/HexE.h"

#ifdef DEBUG // For Encrypted Password Viewer 
#include <filesystem>
#include <fstream>
#endif

const char* MASTER_PASSWORD = "admin"; // TODO hardcoded password to keep it simple - change to whatever you like

/**
 * @brief Displays the main menu to the terminal.
 * 
 */
void displayMenu() {
    std::cout << R"(Password Manager - Main Menu
 1. Add a password
 2. View passwords
 3. Delete a password
 4. Exit
)";
}

int main() {

    // LOCAL VARIABLES
    std::string input;
    int choice;
    bool hasUpdatedData = false; // flag to track if data has changed to allow File Ouput
    std::unordered_map<std::string, std::string> dataMap({}); // create empty map for data
    IEncryption* encrypt = new HEXEncryption(); // NOTE: If you decide on adding OpenSSL, create custom script and use Interface wrapped around library
    std::filesystem::path savePath = CustomIO::GetSavePath("passwords"); // NOTE: path to save data to - change filename to whatever you like
    
    CustomIO::LoadFromFile(savePath, encrypt, dataMap); // load data from file and assign to map passed by ref

    // LAMBDAS

    auto updateData = [&dataMap, &hasUpdatedData](std::string& app, std::string& pass) {
        if(!hasUpdatedData) hasUpdatedData = true; // flag to mark a change was made
        
        dataMap[app] = pass; // add to map
    };

    auto deleteData = [&dataMap, &hasUpdatedData](std::string& app) {
        if(!hasUpdatedData) hasUpdatedData = true; // flag to mark a change was made
        
        if (dataMap.erase(app)) { // erase data from map 
            CustomTerminal::AddMessageToBuffer("Password deleted successfully!", 2);
        } else {
            CustomTerminal::AddMessageToBuffer("Could not find entry.", 2);
        }
    };

#ifdef DEBUG // Encrypted Password Viewer 
    std::cout << "***[DEBUG MODE]****************************" << std::endl;
    savePath.replace_extension(FIO_EXT);
    if (std::filesystem::exists(savePath) && std::filesystem::file_size(savePath) != 0) {
        std::ifstream file(savePath, std::ios::binary);
        if (file.is_open()) {
            std::string line;
            std::cout << "Encrypted file viewer: \n";
            while (std::getline(file, line)) {
                std::cout << "  " << line << "\n";
            }
            std::cout << std::endl;
            file.close();
        }
    }
#endif

#ifndef DEBUG // Avoid entering password when in debug mode
    std::cout << "Enter master password: ";
    CustomIO::GetInput(input);
    if (input != MASTER_PASSWORD) {
        std::cerr << "Access denied!\n\n";
        system("pause");
        return 1;
    }
#endif

    // MAIN LOOP
    do {
        CustomTerminal::ClearTerminal();

#ifdef DEBUG // lets us know we are using debug mode version
        std::cout << "***[DEBUG MODE]****************************" << std::endl;
#endif
        
        CustomTerminal::PrintAndClearBuffer(); // display messages in buffer from last iteration
        displayMenu();

        choice = CustomIO::GetNumericInput();
        switch (choice) {
            case 1: {
                std::string app, pass;
                std::cout << "Enter the app/website name: ";
                CustomIO::GetInput(app);
                std::cout << "Enter the password: ";
                CustomIO::GetInput(pass);
                updateData(app, pass);
                CustomTerminal::AddMessageToBuffer("Password added successfully!", 2);
                break;
            }
            case 2: {
                CustomTerminal::AddMessageToBuffer("Saved Passwords:", 1);
                for (const auto& [app, pass] : dataMap) {
                    CustomTerminal::AddMessageToBuffer(("  - App: " + app + ", Password: " + pass), 1);
                }
                CustomTerminal::AddMessageToBuffer("",1); // space
                break;
            }
            case 3: {
                std::string app;
                std::cout << "Enter the app/website name to delete: ";
                CustomIO::GetInput(app);
                deleteData(app);
                break;
            }
            default:
                CustomTerminal::AddMessageToBuffer("Invalid option. Please try again and select number from menu.", 2);
        }

    } while (choice != 4);

    if (hasUpdatedData && (!CustomIO::SaveToFile(dataMap, savePath, encrypt))) { // avoid saving if no changes were found 
         // if save failed, pause program so the err message will show
        std::cerr << "Error: Unable to save to file." << std::endl;
        system("pause"); 
    }

    return 0;
}
