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
#define NUM_BUILTINS 4
extern char **environ;


/**
 * struct error_h - the stuct to handle error
 * @argv: the argument words
 * @line_count: where is error exist
 * @fname: the filenameWQELR; W Xsawasdfewc t'
 * @status: the error number exit(num) 1,2,3,126,127
 * @path: the path of the command
 */
typedef struct error_h
{
	char **argv;
	char *path;
	unsigned int line_count;

	char *fname;

	int status;

} error_h_t;

char *_getenv(const char *name);
char *get_path(error_h_t *info, char *pathstr, char *cmd);
char *remove_semcolon(const char *path_var, int start, int stop);
char *beginwith(const char *haystack, const char *needle);
int iscommand(error_h_t *info, char *path);
int command_exists(char *command, error_h_t *error_info);
int is_empty_or_whitespace(const char *str);
char **environ_copy();
void free_environ_copy(char **env);
void tokenize_command(char *line, char ***argv, int *numofwords

, error_h_t *error_info);
void execute_with_child(error_h_t *error_info);
void cleanup_memory(char **argv, int numofwords, error_h_t *error_info);
void search_command(error_h_t *error_info);
int iscommand(error_h_t *error_info, char *path);
int is_delimiter(char character, char *delimiter);

void printerr(error_h_t *error_info, const char *message);
void processes(char *line, error_h_t *error_info);
int is_empty_or_whitespace(const char *str);

/*BUILTINS*/
void cd_command(char **argv);
void print_env(void);
int exit_cmd(char **argv, error_h_t *error_info);
int execute_builtins(char **tokens, int num_tokens,
			error_h_t *error_info, char *line);

/*string functions*/
int isnumber(char numbers[]);
int _atoi(char *s);
#endif
