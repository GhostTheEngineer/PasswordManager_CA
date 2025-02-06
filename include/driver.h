/******************************************************************************
 * Project: Password Manager - Console App
 * File: driver.h
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

#pragma once

/**
 * @brief Runs the main loop of the password manager.
 * 
 * This function handles the program's execution, including:
 * - Loading stored passwords from a file.
 * - Prompting the user for authentication (if not in debug mode).
 * - Displaying the main menu and processing user input.
 * - Managing password addition, deletion, and viewing.
 * - Writing updated password data back to the file before exiting.
 * 
 * The function maintains a loop where the user can interact with 
 * the password manager until they choose to exit.
 * 
 * @note In `DEBUG` mode, the encrypted password file is displayed 
 *       at startup, and authentication is skipped.
 */
void runPasswordManager(const char* adminPassword);
