/******************************************************************************
 * Project: Password Manager - Console App
 * File: driver.cpp
 * Description:
 *   The main logic of the program.
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

#include "driver.h"
#include "logger.h"
#include "password_manager.h"
#include "custom_io.h"
#include "custom_terminal.h"
#include "HexE.h"
#include <string>
#include <algorithm>

#ifdef DEBUG // For Encrypted Password Viewer 
#include <filesystem>
#include <fstream>
#endif

/**
 * @brief Displays the main menu to the terminal.
 * 
 */
void displayMenu() {
    CustomIO::PrintToScreen(R"(Password Manager - Main Menu
 1. Add a password
 2. View passwords
 3. Delete a password
 4. Exit
)");
}

void runPasswordManager(const char* adminPassword) {
    
    // STACK VARIABLES
    std::string input;
    int choice;
    HEXEncryption hexEncrypt; // NOTE: If you decide on adding OpenSSL, create custom script and use Interface wrapped around library then swap it here
    std::filesystem::path savePath = CustomIO::GetSavePath("passwords"); // NOTE: path to save data - you may change filename to whatever you like
    PasswordManager manager(CustomIO::LoadFromFile(savePath, hexEncrypt));

#ifdef DEBUG // Encrypted Password Viewer 
    Logger::Info("***[DEBUG MODE]****************************");
    savePath.replace_extension(FIO_EXT);
    if (std::filesystem::exists(savePath) && std::filesystem::file_size(savePath) != 0) {
        std::ifstream file(savePath, std::ios::binary);
        if (file.is_open()) {
            std::string line;
            Logger::Info("Encrypted file viewer: ");
            while (std::getline(file, line)) {
                line = "  - " + line; // add tab and bullet
                Logger::Info(line.c_str());
            }
            file.close();
        }
    }
    system("pause");
#endif

#ifndef DEBUG // Avoid entering password when in debug mode
    CustomIO::PrintToScreen("Enter master password: ");
    CustomIO::GetInput(input);
    if (input != adminPassword) {
        Logger::Error("Access denied!");
        system("pause");
        return;
    }
#endif

    // MAIN LOOP
    do {
        CustomTerminal::ClearTerminal();

#ifdef DEBUG // lets us know we are using debug mode version
        Logger::Info("***[DEBUG MODE]****************************");
#endif
        
        CustomTerminal::PrintAndClearBuffer(); // display messages in buffer from last iteration
        displayMenu();

        choice = CustomIO::GetNumericInput();
        switch (choice) {
            case 1: {
                std::string app, pass;
                CustomIO::PrintToScreen("Enter the app/website name: ");
                CustomIO::GetInputLine(app);
                CustomIO::PrintToScreen("Enter the password: ");
                CustomIO::GetInput(pass);
                manager.AddPassword(app, pass);
                break;
            }
            case 2: {
                manager.ViewPasswords();
                break;
            }
            case 3: {
                std::string app;
                CustomIO::PrintToScreen("Enter the app/website name to delete: ");
                CustomIO::GetInputLine(app);
                manager.DeletePassword(app);
                break;
            }
            case 4: // do nothing - this avoids adding invalid message to buffer 
                break;
            default:
                CustomTerminal::AddMessageToBuffer("Invalid option. Please try again and select number from menu.", 2);
        }

    } while (choice != 4);

    if (!manager.CommitData(savePath, hexEncrypt)) { // attempt to commit data to file, if not successful, pause to display error
        CustomTerminal::PrintAndClearBuffer(); // display messages in buffer
        system("pause"); 
    }

}
