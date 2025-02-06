# **Changelog**  
This file contains information about the current version. To view past versions, please navigate through previous commits.  

## **Version 1.1.0**  
This update introduces **CMake support, improved logging, code restructuring, and enhanced input handling.**  

### **Additions**  
- **`CMakeLists.txt`:** Switched to building with CMake instead of using GCC directly in the command line for easier compiling/building.  
- **`logger.h/cpp`:** Added the ability to log informational messages, warnings, and errors, each accompanied by a timestamp.  

---

### **Changes**  
- **`main.cpp`:** Removed logic from the `main` function (keeping it clear of logic is best practice). This was broken into a `driver` script and a `password_manager` class.  
- **Include (`c_cpp_properties.json`):** Improved header file inclusion for translation units (`.cpp`). Instead of using relative paths like `#include "../include/customio.h"`, a `.vscode/c_cpp_properties.json` file was introduced, allowing direct includes like `#include "customio.h"`.  
- Added a `"No passwords saved!"` message when there are no stored passwords in the buffer/file.  
- **`compile.bat/sh`:** Renamed to `build.bat` and `build.sh` for clarity. Updated scripts to work with CMake for compiling and building the program.  
- **`custom_io.cpp/h`:** `GetInput` previously only handled input up to whitespace. A new function, `GetInputLine`, was introduced to capture entire lines, allowing for app names like `"YouTube ghost"` without truncation.  

---

### **Fixes**  
- None  

