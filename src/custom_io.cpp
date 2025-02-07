/******************************************************************************
 * Project: Password Manager - Console App
 * File: custom_io.cpp
 * Description:
 *   A utilities class for custom file input/output.
 *
 * Copyright © 2025 Ghost - Two Byte Tech. All Rights Reserved.
 *
 * This source code is licensed under the MIT License. For more details, see
 * the LICENSE file in the root directory of this project.
 *
 * Version: v1.1.0
 * Author: Ghost
 * Created On: 1-28-2025
 * Last Modified: 02-06-2025
 *****************************************************************************/

#include "../include/custom_io.h"
#include <fstream>

#define ENCRYPT_DELIM "|"

void CustomIO::PrintToScreen(const char* msg, bool lineBreak) {
    if (lineBreak) std::cout << msg << std::endl;
    else std::cout << msg;
}

int CustomIO::GetNumericInput(int maxAttempts) {

    std::string input;
    int choice = -1;  // Default invalid choice
    int attempts = 0;
    while (true) {
        if(attempts >= maxAttempts) return -1;

        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);

        // Trim whitespace
        input.erase(0, input.find_first_not_of(" \t"));  // Trim left
        input.erase(input.find_last_not_of(" \t") + 1);  // Trim right

        // Check if input is a valid number
        try {
            size_t pos;
            choice = std::stoi(input, &pos);

            // Ensure entire string is consumed (avoiding things like "12abc")
            if (pos == input.size()) {
                return choice;  // Valid number, return
            }
        } catch (const std::exception&) {
            // Invalid input, do nothing (loop continues)
        }

        std::cout << "Invalid input. Please use numbers only.\n";
        attempts++;
    }
}

void CustomIO::GetInput(std::string& input) {
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear remaining buffer to avoid issues on later input captures
}

void CustomIO::GetInputLine(std::string& input) {
    std::getline(std::cin, input);
}

std::string CustomIO::GetExecutablePath() {
    return std::filesystem::current_path().string();
}

std::filesystem::path CustomIO::GetSavePath(const std::string& filename) {
    return (std::filesystem::path(GetExecutablePath()) / (filename + FIO_EXT));
}

bool CustomIO::SaveToFile(const std::unordered_map<std::string, std::string>& passwords, const std::filesystem::path& savePath, const IEncryption& encrypt) {
    
    std::ofstream file(savePath, std::ios::binary | std::ios::trunc);
    if (file.is_open()) {
        for (const auto& [app, pass] : passwords) {
            file << encrypt.encrypt(app) << ENCRYPT_DELIM << encrypt.encrypt(pass) << "\n";
        }
        file.close();
        return true;
    } 

    return false;
}

std::unordered_map<std::string, std::string> CustomIO::LoadFromFile(const std::filesystem::path& savePath, const IEncryption& encrypt) {

    std::unordered_map<std::string, std::string> passwords({});
    std::ifstream file(savePath, std::ios::binary);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t delimiterPos = line.find(ENCRYPT_DELIM);
            if (delimiterPos != std::string::npos) {
                std::string app = line.substr(0, delimiterPos);
                std::string pass = line.substr(delimiterPos + 1);
                passwords[encrypt.decrypt(app)] = encrypt.decrypt(pass);
            }
        }
        file.close();
    }
    return passwords;
}
