#include "main.h"

/**
 * execmd - function to execute the tokenized commands
 * @argv: an array of strings for the commands and arguments
*/

extern char **environ;

void execmd(char **argv)
{
	char *command_passed = NULL, *mainCommand;

	if (*argv != NULL)
	{
		/*set cmmand to the actual command passsed*/
		command_passed = argv[0];
	}

	mainCommand = get_path(command_passed);

	/*check if execution fails*/
	if (execve(mainCommand, argv, environ) == -1)
	{
		perror("Error");		
	}
}

/**
 * get_path - a function to get the full path for the execve function
 * @command: the command to get the full path
 * Return: the fullpath or NULL if no path matches
*/

char *get_path(char *command)
{
	char *path, *pathDup, *pathToken, *fullPath;
	struct stat statFile;

	path = getenv("PATH");

	if (path != NULL)
	{
		pathDup = strdup(path);
	}
	else
	{
		return (NULL);
	}

	pathToken = strtok(pathDup, ":");

	while (pathToken != NULL)
	{
		fullPath = construct_path(pathToken, command);

		if (stat(fullPath, &statFile) == 0)
		{
			free(pathDup);
			return (fullPath);
		}
		else
		{
			free(fullPath);
			pathToken = strtok(NULL, ":");
		}
	}

	free(pathDup);

	if (stat(command, &statFile) == 0)
	{
		return (command);
	}

	return (NULL);
}


/**
 * construct_path - a function for constructing the full path
 * @directory: the directory to add
 * @command: the command to add to the full path
 * Return: the full path
*/

char *construct_path(char *directory, char *command)
{
	int dirLen;
	int commandLen;
	char *fullPath;

	dirLen = strlen(directory);
	commandLen = strlen(command);

	fullPath = malloc(commandLen + dirLen + 2);

	strcpy(fullPath, directory);
	strcat(fullPath, "/");
	strcat(fullPath, command);

	return (fullPath);
}