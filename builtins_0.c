#include "main.h"

/**
 * cd_command - the function to implemen the cd builtin
 * @argv: the arguments received
*/
static char prev_dir[20000] = "";

int cd_command(char **argv)
{
	int dir;
	char *command;
	char *buffer;
	command = argv[1];

	buffer = malloc(strlen(command));

	if (command == NULL)
	{
		dir = chdir(getenv("HOME"));

		if (dir != 0)
		{
			perror("cd");
		}
	}
	else if (strcmp(command, "-") == 0) /*still working on this part*/
	{
		if (prev_dir[0] != '\0')
		{
			dir = chdir(prev_dir);

			if (dir != 0)
			{
				perror("cd");
			}
			else
			{
				setenv("PWD", getcwd(buffer, sizeof(buffer)), 1);
			}
		}
	}
	else
	{
			dir = chdir(command);

			if (dir != 0)
			{
				perror("cd");
			}
			else
			{
				setenv("PWD", getcwd(buffer, sizeof(buffer)), 1);
			}
	}

	return (0);

}

/**
 * exit_cmd - funtion to impement the exit builtin
 * @argv: the variable arument
 * @error_info: a pointer to a a memeber of the error_h_t struct
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
