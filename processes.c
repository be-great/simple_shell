#include "main.h"

/**
* rm_comments - remove the commnets we find
* @line: the string
* @read: number of character readed include '\n'
*/
void rm_comments(char *line, ssize_t *read)
{
	char *commentPos = strchr(line, '#');
	/* Remove newline from the string*/
	if (line[*read - 1] == '\n')
	{
		line[*read - 1] = '\0';
		read--;
	}
	/* Check if '#' is found and it is the */
	/*first character or before it is a space*/
	if (commentPos != NULL)
	{
		/* 1- case `echo dfdf#dlfjkd =   dfdf#dlfjkd*/
		/* 2- case `echo dfdf #dlfjkd =   dfdf*/
		if (commentPos == line || commentPos[-1] == ' ')
			*commentPos = '\0'; /* Truncate the string at the position of '#'*/
	}
}
/**
* processes - handle the common code for interactive and non interactive
* mode.
* Description: Tokenize the command, execute with child process,
* and clean up memory.
* @line: the input readed from the user
* @error_info: the error info
*/

void processes(char *line, error_h_t *error_info)
{
	char **argv;

	int num_tokens;
	int builtins;

	tokenize_command(line, &argv, &num_tokens, error_info);
	builtins = execute_builtins(argv, num_tokens, error_info, line);
	if (builtins != 0)
	{
		search_command(error_info);
	}
		cleanup_memory(argv, num_tokens, error_info);
}
