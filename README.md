# Command Line Interpreter

## Overview
The Command Line Interpreter is a console-based system that allows users to interact with the computer by entering and executing commands. The goal of this project is to create an intelligent tool that can understand user commands in the form of sentences or phrases, interpret their meaning, and respond appropriately.

## Features
- **Console-based command execution**
- **Basic command handling similar to Windows Command Prompt**
- **Supports file system operations**
- **Lightweight and efficient implementation**

## Available Commands
The application supports the following commands:

| Command | Description |
|---------|-------------|
| `CD` | Displays or changes the current directory. |
| `MKDIR` | Creates a new directory. |
| `RMDIR` | Removes a directory. |
| `DIR` | Displays a list of files and subdirectories. |
| `COPY` | Copies one or more files to another location. |
| `HELP` | Displays help information about available commands. |

## Compilation & Requirements
- **Operating System**: Windows (uses Windows API for file operations)
- **Compilation**: Standard C++ compilation using any compatible compiler.
- **Dependencies**: Uses C++ `filesystem` library.
  - [C++ Filesystem Library](https://en.cppreference.com/w/cpp/filesystem)

## Source Files
The project consists of the following source files:
- **CommandLineInterpreter.cpp** - Main file responsible for handling user input.
- **Command.h / Command.cpp** - Manages command-related operations.
- **Parser.h / Parser.cpp** - Handles input parsing and command recognition.

## Class Descriptions
### Command Class
Defines the structure of a command and provides the execution logic.

- Implements the `ICommand` interface with the `execute()` method.
- Includes specialized subclasses:
  - `PrintPath` - Prints the current directory path.
  - `ChangeDirectory` - Changes the current working directory.
  - `PrintDirectory` - Lists contents of the current directory.
  - `CreateDirectory` - Creates a new directory.
  - `CopyFile` - Copies a file to a specified location.
  - `RemoveDirectory` - Deletes a directory.
  - `Help` - Displays information about commands.

### Parser Class
Interprets user input and extracts command information.

- `setCommand(string command)`: Sets a new command.
- `getCommand()`: Retrieves the current command.
- `getKeyWord(string command)`: Extracts the first keyword from the command.
- `getFirstContent(string command)`: Extracts the first argument of a command.
- `getSecondContent(string command)`: Extracts the second argument if available.
- `isACommand(string command)`: Checks if the input is a recognized command.

## Planned Improvements
- Add support for additional commands.
- Implement command-line switches for better flexibility.
- Improve output formatting for better readability.

## Author
Jakub Konior

## License
This project is open-source and available for educational use.

