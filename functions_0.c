#include "main.h"
/**
* handle_variables - handle echo $$ and echo $?
* @error_info: the struct has the error information
* @original_pid: the original pid
*/
void handle_variables(error_h_t *error_info, pid_t original_pid)
{
	int i;

	for (i = 0; error_info->argv[i] != NULL; i++)
	{
		/* Handle $? variable */
		if (_strcmp(error_info->argv[i], "$?") == 0)
		{
			free(error_info->argv[i]);
			error_info->argv[i] = intToString_2(error_info->status);

		}
		/* Handle $$ variable */
		else if (_strcmp(error_info->argv[i], "$$") == 0)
		{
			char pid_str[10];

			pidToString(original_pid, pid_str, sizeof(pid_str));
			free(error_info->argv[i]);
			error_info->argv[i] = _strdup(pid_str);
		}
		/* Handle other environment variables starting with $*/
		else if (error_info->argv[i][0] == '$' && error_info->argv[i][1] != '\0')
		{
			char *variable = NULL;

			size_t len = _strlen(error_info->argv[i]) - 1;
			char *newstr;

			int escape = 1;

			newstr = (char *)malloc(len + 2);
			_strncpy(newstr, error_info->argv[i] + escape, len + 1);
			newstr[len + 1] = '\0';  /* Null-terminate the string */
			variable = _getenv(newstr);
			free(error_info->argv[i]);
			if (variable != NULL && variable[0] != '\0')
				error_info->argv[i] = _strdup(variable);
			else
				error_info->argv[i] = _strdup("");
			free(newstr);
			free(variable);
		}
	}
}
/**
* tokenize_command - Tokenize the command line.
* @line: The command line to tokenize.
* @argv: Pointer to store the resulting array of strings (tokens).
* @numofwords: Pointer to store the number of tokens.
* @error_info: the error struct
*/
void tokenize_command(char *line, char ***argv, int *numofwords,

		error_h_t *error_info)
{
	char *lineptr_copy = _strdup(line); /* Need to free this later */

	/* Use custom _strtow function for tokenization */
	*argv = _strtow(lineptr_copy, " \n");
	*numofwords = 0;
	while ((*argv)[*numofwords] != NULL)
	{
		(*numofwords)++;
	}

	/* Populate error_info with relevant information */
	if (*numofwords > 0)
		error_info->line_count++;

	error_info->argv = *argv;

	/* Cleanup allocated memory */
	free(lineptr_copy);
}

/**
* execute_with_child - Execute the command with a child process.
* @error_info: Pointer to the error_h_t structure to update status.
*/
void execute_with_child(error_h_t *error_info)
{
	pid_t child_pid;


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		handle_variables(error_info, get_original_pid());
		if (execve(error_info->path, error_info->argv, environ_copy()) == -1)
		{
			if (errno == EACCES)
				error_info->status = (126), exit(126);
			error_info->status = (1), exit(1);
		}
	}
	else
	{
		wait(&(error_info->status));
		if (WIFEXITED(error_info->status))
		{
			error_info->status = WEXITSTATUS(error_info->status);
			if (error_info->status == 126)
				printerr(error_info, "Permission denied");
		}
	}
}




/**
* cleanup_memory - Clean up allocated memory.
* @argv: The array of strings to free.
* @numofwords: The number of tokens in the array.
* @error_info: the struct of the error
*/
void cleanup_memory(char **argv, int numofwords, error_h_t *error_info)
{
	int i;

	(void)(error_info);

	/* Cleanup allocated memory */
	for (i = 0; i < numofwords; i++)
		free(argv[i]);
	free(argv);
	error_info->argv = NULL;
	error_info->path = NULL;
}
