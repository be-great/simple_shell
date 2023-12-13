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
- **File Input:** Allows running shell scripts and allows running a file. Usage: simple_shell [filename].

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Unix-like operating system

### Installation

1. **Clone the repository and compile the code:**

   ```bash
   git clone https://github.com/be-great/simple_shell.git && \
   cd simple_shell && \
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

2. **Run the shell:**

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
|processes.c| handler the shell program|
|functions_0.c|tokenizer , free , fork functions|
|functions_1.c|make copy of the enviroment ,free the new enviroment located , check if str is empty of just spaces|
|error_handler.c|print the error|
|_getenv.c| write the funciton _getenv from scratch|
|path_0.c|functions that handle the path task|
|path_1.c|additional functions that handle the path task|



## Run Command:-

    $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              "
echo "$shell_input" |  sh
echo "$shell_input" |  ./hsh