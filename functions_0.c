#include "main.h"
/**
* tokenize_command - Tokenize the command line.
* @line: The command line to tokenize.
* @argv: Pointer to store the resulting array of strings (tokens).
* @numofwords: Pointer to store the number of tokens.
*/
void tokenize_command(char *line, char ***argv, int *numofwords)
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

	/* Cleanup allocated memory */
	free(lineptr_copy);
}

/**
* execute_with_child - Execute the command with a child process.
* @argv: The array of strings representing the command.
*/
void execute_with_child(char **argv)
{
	/* Execution part with child process */
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error in fork:");
		exit(1);
	}

	if (child_pid == 0)
	{
		execmd(argv);
	}
	else
	{
		wait(NULL);
	}
}

/**
* cleanup_memory - Clean up allocated memory.
* @argv: The array of strings to free.
* @numofwords: The number of tokens in the array.
*/
void cleanup_memory(char **argv, int numofwords)
{
	int i;

	/* Cleanup allocated memory */
	for (i = 0; i < numofwords; i++)
		free(argv[i]);
	free(argv);
}
