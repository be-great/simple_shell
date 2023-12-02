#include "main.h"


/**
* execmd - function to execute the tokenized commands
* @error_info: an array of strings for the commands and arguments
*/
void execmd(error_h_t *error_info)
{
	char *command_passed = NULL, *mainCommand;

	char **new_env, *lc_collate_value;

    /* Get the value of LC_COLLATE from the current environment */
	/*lc_collate : effect the string sorting if it's not set propery*/
	/*so we have to set at as default to 'C'*/
	lc_collate_value = getenv("LC_COLLATE");
	/* Check if LC_COLLATE is set, if not, use a default*/
	/* value or handle accordingly*/
	if (lc_collate_value == NULL)
	{
		lc_collate_value = "C";  /* Default to "C" locale or modify as needed*/
	}
    /*we create a copy of the envrorment each time we call execve command*/
    /* then we free it*/
	new_env = environ_copy();
	
    /* Set LC_COLLATE in the copied environment */
    setenv("LC_COLLATE", lc_collate_value, 1); /* 1 to override existing value */

    if (error_info && error_info->argv != NULL)
	{
		/*set cmmand to the actual command passsed*/
		command_passed = error_info->argv[0];
	}

	mainCommand = get_path(command_passed);

	/*check if execution fails*/
	if	(mainCommand == NULL ||
				execve(mainCommand, error_info->argv, new_env) == -1)
	{
			error_info->status = 127; /* Default status for command not found*/
			printerr(error_info, "not found");
			exit(error_info->status);
			free_environ_copy(new_env);
			free(mainCommand);
	}

	/* Free the dynamically allocated memory */
	free_environ_copy(new_env);
	free(mainCommand);

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
	size_t dirLen;
	size_t commandLen;
	char *fullPath;

    if (directory == NULL || command == NULL)
    {
        perror("/bin/sh: 1: construct_path:");
        exit(EXIT_FAILURE);
    }
	dirLen = strlen(directory);
	commandLen = strlen(command);
    /* Check for potential overflow before allocating memory*/
    if (SIZE_MAX - dirLen < commandLen + 2) {
        perror("/bin/sh: 1: construct_path:");
        exit(EXIT_FAILURE);
    }
	fullPath = malloc(commandLen + dirLen + 2);
    if (fullPath == NULL)
    {
        perror("/bin/sh: 1: construct_path:");
        exit(EXIT_FAILURE);
    }

	strcpy(fullPath, directory);
	strcat(fullPath, "/");
	strcat(fullPath, command);

	return (fullPath);
}
