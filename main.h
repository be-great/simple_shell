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
#include <fcntl.h>
#define PATH_MAX 4096
#define NUM_BUILTIN 5
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

/**
 * struct builtin_cmd - the struct to handle builtins
 * @command_name: the name of the command
 * @builtin_func: the function pointer to the various functions
*/
typedef struct builtin_cmd
{
	char *command_name;

	int (*builtin_func)(char **argv, error_h_t *error_info);

} builtin_cmd_t;


/*FUNCTION PROTOTYPES*/
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
char *addprinterr(char *command);
int dirError(char *command, error_h_t *error_info, char *buffer);
int is_empty_or_whitespace(const char *str);
void filerror(char *prname, char *msg0, char *fname, char *msg1);
void rm_comments(char *line, ssize_t *read);
void cleanup_env(void);
int add_environ(char **env, char *name, char *value, int i);

/*BUILTINS*/
int cd_command(char **argv, error_h_t *error_info);
int print_env(char **argv, error_h_t *error_info);
int exit_cmd(char **argv, error_h_t *error_info);
int cdDash(char *command, size_t maxpath, error_h_t *error_info);
int setenv_builtin(char **argv, error_h_t *error_info);
int unsetenv_builtin(char **argv, error_h_t *error_info);
int changeDir(char *command, size_t maxpath, error_h_t *error_info);
builtin_cmd_t *initbuiltin(void);
int execute_builtins(char **tokens, int num_tokens,
			error_h_t *error_info, char *line, char **commands, int numofcommands);

/*string functions*/
int isnumber(char numbers[]);
int _atoi(char *s);

/*string_manipulation*/
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _putchar(char c);
char *_memset(char *s, char b, unsigned int n);
char *_strchr(char *s, char c);
void _puts(char *str);
char *_strdup(char *str);
void intToString(int number, char *buffer);
char *_strncpy(char *dest, char *src, int n);
int numlen(int number);
char *intToString_2(int number);
void pidToString(pid_t pid, char *str, size_t size);
size_t pidlen(pid_t pid);
int _strncmp(const char *str1, const char *str2, size_t n);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
/*Task ;*/
char **split_commands(char *line, int *num_commands);
void free_commands(char **commands, int numofcommands);
/*Task 16*/
void execute_from_file(error_h_t *error_info);
ssize_t read_line(int fd, char **line, size_t *line_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*Task 7 : remove the use of strtok*/
char **_strtow(char *str, const char *delim);
/*Task 14 : handle variable replacement*/
pid_t get_original_pid(void);
#endif
