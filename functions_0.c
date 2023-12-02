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
* @argv: The array of strings representing the command.
* @error_info: Pointer to the error_h_t structure to update status.
*/
void execute_with_child(char **argv, error_h_t *error_info)
{
	pid_t child_pid = fork();
	(void) argv;

	if (child_pid == -1)
	{
		perror("Error in fork:");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		execmd(error_info);
	}
	else
	{
		int status = 0;
        pid_t waited_pid = waitpid(child_pid, &status, 0);
		 if (waited_pid == -1) {
            perror("waitpid");
            error_info->status = EXIT_FAILURE;
        } else if (WIFEXITED(status)) {
            error_info->status = WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            error_info->status = EXIT_FAILURE;
        } else if (WIFSTOPPED(status)) {
            dprintf(STDERR_FILENO, "Child process stopped\n");
            error_info->status = EXIT_FAILURE;
        } else if (WIFCONTINUED(status)) {
            dprintf(STDERR_FILENO, "Child process continued\n");
            error_info->status = EXIT_FAILURE;
        } else {
            dprintf(STDERR_FILENO, "Unexpected exit status\n");
            error_info->status = EXIT_FAILURE;
        }
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
