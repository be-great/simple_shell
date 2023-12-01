#include "main.h"

/**
* main - Entry point
* @argc: number of argument passed
* @argv: argument vector of string
* Return: 0 Always (Success)
*/
int main(int argc, char **argv)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t read;
	(void)argc, (void)argv;

	/* Non-interactive mode*/
	if (!isatty(STDIN_FILENO))
	{
		/* Read lines from standard input using getline*/
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			processes(line);
		}
		/*Cleanup*/
		free(line);
	}
	/* Interactive mode*/
	else
	{
		while (1)
		{
			printf("$ ");
			read = getline(&line, &len, stdin);
			if (read == -1)
			{
				perror("Error reading line.");
				free(line);
				exit(1);
			}

			processes(line);
		}
	}

	return (0);
}
