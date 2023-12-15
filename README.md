# simple_shell
A simple shell implementation in C.


<img src="https://github.com/be-great/simple_shell/blob/main/images/2.png">

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Authors](#authors)

## Introduction

This project is a simple shell implementation written in C. It provides a basic command-line interface for users to interact with the system. Inspired by the fundamental principles of Unix/bash shells, our simple shell aims to offer a functional environment for executing commands and managing processes.

## Features

- **Command Execution:** Execute commands entered by the user.
- **Built-in Commands:** Supports built-in commands like `cd`, `exit`, etc.
- **Error Handling:** Provides informative error messages for invalid , same way a bash shell does.
- **File Input:** Allows running shell scripts and allows running a file.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Unix-like operating system / a terminal

### Installation

After each step, press the `enter` key

1. **Clone the repository:**

   ```bash
   git clone https://github.com/be-great/simple_shell.git

2. **Navigate to the project directory**:

   ```bash
   cd simple_shell

3. **Compile the code:**

   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

4. **Run the shell:**

   ```bash
   ./hsh

## Usage

- **Basic Usage:**
- Enter commands and press Enter to execute.
- Use `exit` or `Ctrl + D`to exit the shell.

- **Built-in Commands:**
- `cd`: Change the current working directory.
- `exit`: Exit the shell.
- `exit status`: Exits the shell with a status code.
- `setenv`: Sets an environment varable or modify an existing one.
- `unsetenv`: Deletes an environment varable.
- **File Input:**
- Take a file as an input `simple_shell [filename]`.



## Authors

- Isaiah Woko
- Ahed Eisa(be-great)


## Files

|File|Description|
|---|---|
|main.c|starting point of the program|
|main.h|the header file for the shell|
|processes.c| handler the shell program|
|functions_0.c|tokenizer , free , fork functions|
|functions_1.c|make copy of the enviroment ,free the new enviroment located , check if str is empty of just spaces|
|error_handle.c|print the error and handle other error messages|
|_getenv.c| write the funciton _getenv from scratch|
|path_0.c|functions that handle the path task|
|path_1.c|additional functions that handle the path task|
|string_manipulation_0.c|hanle custom string functions|
|string_manipulation_1.c|hanle custom string functions|
|string_manipulation_2.c|hanle custom string functions|
|string_manipulation_3.c|hanle custom string functions|
|string_manipulation_4.c|hanle custom string functions|
|execute_builtins.c|handle the execution of the builtins|
|builtins_0.c|handle the builtin commands|
|builtins_1.c|handle additional builtin commands|
|strtok.c|custom function that behaves like strtok|
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        "
echo "$shell_input" |  sh
echo "$shell_input" |  ./hsh