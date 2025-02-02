/******************************************************************************
 * Project: Password Manager - Console App
 * File: custom_io.h
 * Description:
 *   A utilities class for custom file input/output.
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
#include "../include/IEncryption.h"
#include <iostream>
#include <filesystem>
#include <unordered_map>

#define FIO_EXT ".pwdb"

/**
 * @class CustomIO
 * @brief Provides utility functions for input handling and file management.
 * 
 * The CustomIO class is responsible for managing user input validation and file operations. 
 * It includes methods for retrieving the executable's path, constructing save paths, and 
 * securely saving and loading encrypted key-value data. 
 * 
 * This class is designed to facilitate modular and reusable I/O handling, ensuring 
 * structured file management and robust input validation.
 */
class CustomIO {
public:

    /**
     * @brief Reads and validates a numeric input from the user.
     *
     * This function continuously prompts the user for input, ensuring it is a valid integer.
     * If the input contains non-numeric characters or is empty, the user is prompted again.
     * Leading and trailing whitespace are trimmed before processing.
     * 
     * The function allows a maximum number of attempts (`max`), which defaults to `4`.
     * If the user exceeds the allowed attempts, the function returns `-1`.
     * 
     * @param maxAttempts The maximum number of attempts before returning `-1` (default: 4).
     * @return The valid integer input from the user, or `-1` if the maximum attempts are reached.
     */
    static int GetNumericInput(int maxAttempts = 4);

    /**
     * @brief Reads input from the user. 
     * 
     * This is a safe way to ensure the buffer is always clear
     * after reading input to avoid issues in later input captures.
     * 
     * Note, any whitespace in the input will ignore any input beyond it.
     * 
     * @param input string object reference to hold user input.
     */
    static void GetInput(std::string& input);

    /**
     * @brief Retrieves the path of the current working directory where the executable resides.
     * 
     * @return The current working directory as a string.
     */
    static std::string GetExecutablePath();

    /**
     * @brief Constructs a full save path by appending the given filename to the executable's directory.
     * 
     * @param filename The name of the file to append to the directory path.
     * @return The full path to the file as a string.
     */
    static std::filesystem::path GetSavePath(const std::string& filename);

    /**
     * @brief Saves a map of key-value pairs to a file, encrypting each key and value.
     * 
     * @param passwords The map containing key-value pairs (e.g., app names and passwords).
     * @param savePath The path to the file where data will be saved.
     * @param key The encryption key used to encrypt the data.
     */
    static bool SaveToFile(const std::unordered_map<std::string, std::string>& passwords, std::filesystem::path& savePath, IEncryption*& encrypt);

    /**
     * @brief Loads decrypted key-value pairs from a file into the provided map.
     * 
     * Reads an encrypted file, decrypts each key-value pair, and stores them in the given 
     * unordered map.
     * 
     * @param savePath The path to the file from which data will be loaded. The file extension 
     *                 is automatically corrected if necessary.
     * @param encrypt A reference to the encryption instance used to decrypt data.
     * @param passwords A reference to the map where decrypted key-value pairs will be stored.
     */
    static void LoadFromFile(std::filesystem::path& filename, IEncryption*& encrypt, std::unordered_map<std::string, std::string>& passwords);

};
