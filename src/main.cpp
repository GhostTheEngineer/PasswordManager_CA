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
 * Version: v1.1.0
 * Author: Ghost
 * Created On: 1-28-2025
 * Last Modified: 02-06-2025
 *****************************************************************************/

#include "driver.h"

const char* MASTER_PASSWORD = "admin"; // TODO hardcoded password to keep it simple - change to whatever you like

int main() {

    runPasswordManager(MASTER_PASSWORD);
    
}
