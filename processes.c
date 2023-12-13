#include "main.h"

/**
 * read_line - read the line from input file
 * @fd: file description
 * @line: the line
 * @line_size: line size
 * Return: readed line
 */
ssize_t read_line(int fd, char **line, size_t *line_size)
{
	ssize_t read_size = 0;
	ssize_t total_size = 0;
	char buffer;

	while ((read_size = read(fd, &buffer, 1)) > 0)
	{
		if (total_size >= (ssize_t)*line_size - 2)
		{
			/* Double the buffer size if needed */
			*line_size *= 2;
			*line = _realloc(*line, *line_size / 2, *line_size);
			if (*line == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		/* Store the character in the line buffer */
		(*line)[total_size++] = buffer;

		if (buffer == '\n')
		{
			/* Null-terminate the string */
			(*line)[total_size] = '\0';
			break;
		}
	}

	if (read_size == 0 && total_size == 0)
	{
		return (0); /* End of file */
	}

	return (total_size);
}

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
	char **commands;
	char *command;
	int num_commands;
	char **argv;
	int num_tokens;
	int builtins, i;


	/* Split commands using ';' */
	commands = split_commands(line, &num_commands);

	for (i = 0; i < num_commands; i++)
	{
		command = commands[i];
		tokenize_command(command, &argv, &num_tokens, error_info);
		builtins = execute_builtins(argv, num_tokens, error_info, line,
				commands, num_commands);
		if (builtins != 0)
		{
			search_command(error_info);
		}
		cleanup_memory(argv, num_tokens, error_info);
	}

	/* Free memory allocated for commands */
	free_commands(commands, num_commands);

}

/**
 * split_commands - split a line into individual commands separated by ';'
 * @line: the input line
 * @num_commands: pointer to store the number of commands
 * Return: array of commands
 */
char **split_commands(char *line, int *num_commands)
{
	char **commands = NULL;
	char *token;
	int i = 0;

	token = strtok(line, ";");
	while (token != NULL)
	{
		commands = realloc(commands, (i + 1) * sizeof(char *));
		if (commands == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		commands[i] = _strdup(token);
		if (commands[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		i++;
		token = strtok(NULL, ";");
	}

	*num_commands = i;
	return (commands);
}
/**
 * free_commands - to free the commands
 * @commands: the commands to free
 * @numofcommands: the number of commands
 */
void free_commands(char **commands, int numofcommands)
{
	int i;

	for (i = 0; i < numofcommands; i++)
	{
		free(commands[i]);
	}
	free(commands);
}























































































































