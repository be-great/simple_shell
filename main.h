#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

void processes(char *line);
char *get_location(char *command);
void execmd(char **argv);
void cleanup_memory(char **argv, int numofwords);
void execute_with_child(char **argv);
void tokenize_command(char *line, char ***argv, int *numofwords);
#endif
