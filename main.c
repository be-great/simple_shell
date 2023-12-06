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
* interactive - handle the interactive mode
* @error_info: passing the error info structure
*/
void interactive(error_h_t *error_info)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			/* Check for end of file */
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("getline");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		/*-----------remove the comment*/
		if (read > 0)
			rm_comments(line, &read);
		/*-------------------------------*/
		processes(line, error_info);
	}

	free(line);
}
/**
* None_interactive - handle the None interactive mode
* @error_info: passing the error info structure
*/
void None_interactive(error_h_t *error_info)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		/*-----------remove the comment*/
		if (read > 0)
			rm_comments(line, &read);
		/*-------------------------------*/
		if (is_empty_or_whitespace(line))
		{
			/* Skip processing for empty/whitespace lines */
			continue;
		}
		processes(line, error_info);
		if (error_info->status != 0)
		{
			free(line), exit(error_info->status);
		}
	}
	if (feof(stdin))
	{
		/* End of file reached, cleanup */
		free(line), exit(EXIT_SUCCESS);
	}
	else
	{
		perror("getline"), free(line);
		exit(EXIT_FAILURE);
	}
}

/**
* main - Entry point
* @argc: number of argument passed
* @argv: argument vector of string
* Return: 0 Always (Success)
*/
int main(int argc, char **argv)
{
	error_h_t error_info;
	/* Initialize error_info structure */
	memset(&error_info, 0, sizeof(error_h_t));
	/* Set filename */
	error_info.fname = argv[0];

	(void)argc;
	/* Non-interactive mode */
	if (!isatty(STDIN_FILENO))
	{
		None_interactive(&error_info);
	}
	/* Interactive mode */
	else
	{
		interactive(&error_info);
	}

	return (error_info.status);
}
