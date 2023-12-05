#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <stdint.h>
#include <ctype.h>
#define NUM_BUILTINS 4;
extern char **environ;


/**
 * struct error_h - the stuct to handle error
 * @argv: the argument words
 * @line_count: where is error exist
 * @fname: the filenameWQELR; W Xsawasdfewc t'
 * @status: the error number exit(num) 1,2,3,126,127
 */
typedef struct error_h
{
	char **argv;

	unsigned int line_count;

	char *fname;

	int status;

} error_h_t;
void processes(char *line, error_h_t *error_info);
char *get_path(char *command);
char *construct_path(char *directory, char *command);
void execmd(error_h_t *error_info);
void cleanup_memory(char **argv, int numofwords);
void execute_with_child(char **argv, error_h_t *error_info);
void tokenize_command(char *line, char ***argv, int *numofwords,
					error_h_t *error_info);
void printerr(error_h_t *error_info, const char *message);
char **environ_copy();
void free_environ_copy(char **env);
int is_empty_or_whitespace(const char *str);

/*BUILTINS*/
void cd_command(char **argv);
void print_env();
void exit_cmd(char **argv);
int execute_builtins(char **tokens, int num_tokens);
#endif
