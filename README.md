# Password Manager (Console App)

A intermediate **C++ Password Manager** project that teaches **file I/O, encryption, and terminal handling** while maintaining clean and modular code.

This tutorial project **does not use third-party libraries** for simplicity, but follows good programming practices, including:
- **Custom File I/O Handling** (`CustomFileIO`)
- **Custom Terminal Management** (`CustomTerminal`)
- **Hex-based Encryption** (`HEXEncryption`)
- **Interface-Driven Design** (`IEncryption`)

## 📌 How It Works
This console-based **Password Manager** allows users to:
1. **Store passwords securely** (encrypted using Hex encoding)
2. **View saved passwords**
3. **Delete stored passwords**
4. **Exit the program (saves changes)**

Passwords are stored in a **binary file (`passwords.pwdb`)** inside the same directory as the executable.

## 🛠 Project Structure
```
/PasswordManager
│── /src
│   ├── main.cpp               # Main entry point
│   ├── custom_io.cpp          # Handles file I/O (saving/loading passwords)
│   ├── custom_terminal.cpp    # Terminal utilities (clearing screen, buffering messages)
│   ├── HexE.cpp               # Implements hex-based encryption
│── /include
│   ├── custom_io.h            # Header for file I/O
│   ├── custom_terminal.h      # Header for terminal utilities
│   ├── HexE.h                 # Header for hex-based encryption
│   ├── IEncryption.h          # Encryption interface
│── compile.bat                # Windows batch script for compilation
│── run.bat                    # Windows batch script for running the executable
│── compile.sh                 # (Assumed) Shell script for Mac/Linux
│── run.sh                     # (Assumed) Shell script for Mac/Linux
```

## Requirements

To build and run this project, ensure you have the following dependencies installed:

### **Build System**
- **CMake** (version 3.10 or higher)  
  - Download: [https://cmake.org/download/](https://cmake.org/download/)

### **Compilers**
- **GCC** (MinGW for Windows) or **Clang**
  - Windows: Install via [MSYS2](https://www.msys2.org/)
  - Linux/macOS: Install via package manager (`apt`, `brew`, `dnf`, etc.)
- **Microsoft Visual C++ (MSVC)**
  - Install via **Visual Studio** with the "Desktop Development with C++" workload.

## 🏗️ Compilation & Running

### 🔹 Windows
1. **Open Command Prompt**
2. **Compile the project**:
   ```sh
   compile.bat Debug  # Compiles in Debug mode
   compile.bat Release  # Compiles in Release mode
   ```
3. **Run the executable**:
   ```sh
   run.bat [BUILD MODE]
   ```

### 🔹 Mac & Linux
1. **Open Terminal**
2. **Compile the project**:
   ```sh
   chmod +x compile.sh
   ./compile.sh Debug  # Compiles in Debug mode
   ./compile.sh Release  # Compiles in Release mode
   ```
3. **Run the executable**:
   ```sh
   chmod +x run.sh
   run.sh [BUILD MODE]
   ```

## 🔐 Encryption Mechanism
- Uses **Hex-based encoding** (`HEXEncryption`) for simple obfuscation.
- Implements **`IEncryption` Interface**, allowing easy swapping with stronger encryption (e.g., OpenSSL).

## 🚀 Future Improvements
- 🔄 **Use OpenSSL for stronger encryption**
- 📁 **Improve file structure for modularity**
- 🎨 **Add a GUI for better user experience**

## 📝 License
This project is licensed under the **MIT License**. See `LICENSE` for details.

## 📢 Author
**Ghost - Two Byte Tech**
- **TikTok ->** [click here](https://www.tiktok.com/@ghosttheengineer)
- **YouTube ->** [click here](https://www.youtube.com/@GhostTheEngineer)
- **Discord ->** [click here](https://www.discord.gg/NxB6v5ma5A)

---
Enjoy coding! 🚀
