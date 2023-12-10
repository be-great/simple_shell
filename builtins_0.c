#include "main.h"

/**
 * cd_command - the function to implemen the cd builtin
 * @argv: the arguments received
 * @error_info: Pointer to the error_h_t structure
 * Return: 1 or -1 for failure and sucess
*/

int cd_command(char **argv, error_h_t *error_info)
{
	int dir;
	char *command, *homePath;

	command = argv[1];
	if (command == NULL)
	{
		homePath = _getenv("HOME");

		if (homePath != NULL)
		{
			dir = chdir(homePath);

			if (dir != 0)
			{
				if (errno == EACCES)
				{
					char *message = addprinterr(command);

					printerr(error_info, message);
					free(message);
				}
				else
				{
					perror("cd");
					return (-1);
				}
			}
		}
	}
	else
	{
		dir = changeDir(command, PATH_MAX, error_info);
	}
	return (0);
}


/**
 * changeDir - a helping function to implement changing directory
 * @command: the command passed
 * @maxpath: maximum dir size
 * @error_info: Pointer to the error_h_t structure
 * Return: -1 for failure
*/

int changeDir(char *command, size_t maxpath, error_h_t *error_info)
{
	int dir;
	char *buffer;

	buffer = malloc(PATH_MAX);

	if (buffer == NULL)
	{
		perror("malloc allocation failed");
		return (-1);
	}

	dir = chdir(command);

	if (dir != 0)
	{
		dirError(command, error_info, buffer);
	}
	else
	{
		if (getcwd(buffer, maxpath) == NULL)
		{
			perror("getcwd");
			free(buffer);
			return (-1);
		}
		else
		{
			if (setenv("PWD", buffer, 1) != 0)
			{
				perror("setenv");
				free(buffer);
				return (-1);
			}
		}
		free(buffer);
	}
	return (0);
}




/**
 * exit_cmd - funtion to impement the exit builtin
 * @argv: the variable arument
 * @error_info: a pointer to a memeber of the error_h_t struct
 * Return: the status of the exit
*/

int exit_cmd(char **argv, error_h_t *error_info)
{
	if (argv[0] != NULL && (argv[1] == NULL ||
			(_strcmp(argv[0], "exit") == 0 && argv[1] == NULL)))
	{
		return (0);
	}

	else if (argv[1] != NULL && argv[0] != NULL)
	{	/*check if argv[1] avild number and None negative*/
		if (isnumber(argv[1]) && argv[1][0] != '-')
		{
			return (_atoi(argv[1]));
		}
		/* if it's not a number print error*/
		else
		{
			printerr(error_info, "Illegal number: ");
			write(STDERR_FILENO, argv[1], _strlen(argv[1]));
			write(STDERR_FILENO, "\n", 1);
			return (2);
		}


	}
	return (0);
}


/**
 * print_env- a function to handle printing env
 * Return (void)
*/
void print_env(void)
{
	char **env_print = environ;
	size_t len;

	while (*env_print != NULL)
	{
		len = 0;

		while ((*env_print)[len] != '\0')
		{
			len++;
		}

		write(STDOUT_FILENO, *env_print, len);
		write(STDOUT_FILENO, "\n", 1);

		env_print++;
	}
}
