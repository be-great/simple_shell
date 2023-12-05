#include "main.h"
/**
* tokenize_command - Tokenize the command line.
* @line: The command line to tokenize.
* @argv: Pointer to store the resulting array of strings (tokens).
* @numofwords: Pointer to store the number of tokens.
* @error_info: the error struct
*/
void tokenize_command(char *line, char ***argv, int *numofwords

, error_h_t *error_info)
{
	char *lineptr_copy = strdup(line); /* Need to free this later */

	char *token;

	int i;

	*numofwords = 0;
	token = strtok(lineptr_copy, " \n");

	while (token != NULL)
	{
		(*numofwords)++;
		token = strtok(NULL, " \n");
	}

	/* Allocate space to hold the array of strings */
	*argv = malloc(sizeof(char *) * (*numofwords + 1));
	/* Store each token in the argv array */
	token = strtok(line, " \n");

	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = strdup(token); /* Need to free these later */
		token = strtok(NULL, " \n");
	}
	(*argv)[*numofwords] = NULL;

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
		/* TODO: PUT ERROR FUNCTION */
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(error_info->path, error_info->argv, environ_copy()) == -1)
		{
			if (errno == EACCES)
				error_info->status = (126), exit(126);
			error_info->status = (1), exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
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
