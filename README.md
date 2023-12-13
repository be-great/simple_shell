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
- [Acknowledgments](#acknowledgments)

## Introduction

This project is a simple shell implementation written in C. It provides a basic command-line interface for users to interact with the system.

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