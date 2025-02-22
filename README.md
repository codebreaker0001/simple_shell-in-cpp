# Simple Shell Implementation in C++

## Overview
This project is a basic shell implemented in C++. It supports fundamental shell commands and provides a simple command-line interface for executing them.

## Features
- **Custom Shell Prompt**: Provides an interactive command-line interface.
- **Basic Commands Support**:
  - `type` - Displays the content of a file.
  - `echo` - Prints text to the console.
  - `exit` - Exits the shell.
  - `ls` - Lists files in the current directory.
  - And more...
- **Command Parsing**: Supports basic command parsing and execution.
- **Error Handling**: Displays appropriate error messages for invalid commands.

## Prerequisites
- C++ Compiler (GCC or Clang recommended)
- CMake (optional for build automation)

## Installation & Usage
1. Clone the repository:
   ```sh
   git clone https://github.com/your-username/shell-project.git
   cd shell-project
   ```
2. Compile the program:
   ```sh
   g++ shell.cpp -o shell
   ```
3. Run the shell:
   ```sh
   ./shell
   ```

## Example Usage
```
$ ./shell
myshell> echo Hello, World!
Hello, World!
myshell> ls
file1.txt  file2.cpp  shell.cpp
myshell> type file1.txt
(file contents displayed)
myshell> exit
```

## Future Enhancements
- Support for additional commands
- Implementing piping (`|`) and redirection (`>` and `<`)
- Adding background process execution (`&`)
- Enhancing command history functionality

## Contributing
Feel free to fork the repository and submit pull requests. Contributions to improve functionality and add new features are welcome!


