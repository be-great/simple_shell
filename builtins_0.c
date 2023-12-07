#include "main.h"

/**
 * cd_command - the function to implemen the cd builtin
 * @argv: the arguments received
 * Return: 1 or -1 for failure and sucess
*/

int cd_command(char **argv)
{
	int dir;
	char *command, *buffer;

	command = argv[1];
	if (command == NULL)
	{
		dir = chdir(_getenv("HOME"));
		if (dir != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{
		buffer = malloc(PATH_MAX);

		if (buffer == NULL)
		{
			perror("malloc");
			return (-1);
		}
		else
		{
			dir = changeDir(command, buffer, PATH_MAX);

			free(buffer);
		}
	}
	return (0);
}


/**
 * changeDir - a helping function to implement changing directory
 * @command: the command passed
 * @buffer: the buffe for storing directory path
 * @maxpath: maximum dir size
 * Return: -1 for failure
*/

int changeDir(char *command, char *buffer, size_t maxpath)
{
	int dir;

	dir = chdir(command);

	if (dir != 0)
	{
		perror("cd");
		return (dir);
	}
	else
	{
		if (getcwd(buffer, maxpath) == NULL)
		{
			perror("getcwd");
			return (-1);
		}
		else
		{
			setenv("PWD", buffer, 1);
		}
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
			(strcmp(argv[0], "exit") == 0 && argv[1] == NULL)))
	{
		return (0);
	}

	else if (argv[1] != NULL && argv[0] != NULL)
	{	/*check if argv[1] avild number and None negative*/
		if (isnumber(argv[1]) && argv[1][0] != '-')
		{
			return (_atoi(argv[1]));
		}
		/* if it's not a nubmer print error*/
		else
		{
			printerr(error_info, "Illegal number: ");
			dprintf(STDERR_FILENO, "%s\n", argv[1]);
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
