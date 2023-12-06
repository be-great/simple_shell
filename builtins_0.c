#include "main.h"

/**
 * cd_command - the function to implemen the cd builtin
 * @argv: the arguments received
*/
static char prev_dir[20000] = "";

void cd_command(char **argv)
{
	int dir;
	char *command;
	/*still looking for a way not to hardcode the buffer size*/
	char buffer[20000];
	command = argv[1];
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

}

/**
 * exit_cmd - funtion to impement the exit builtin
 * @arg: the variable arument
 * Return: the status of the exit
*/

int exit_cmd(char **argv, error_h_t *error_info)
{
	if (argv[1] != NULL && argv[0] != NULL)
	{	/*check if argv[1] avild number and None negative*/
		if (isnumber(argv[1]) && argv[1][0] != '-')
		{
			return (_atoi(argv[1]));
		}
		/* if it's not a nubmer print error*/
		else
		{
			printerr(error_info, "Illegal number: ");
			dprintf(STDERR_FILENO,"%s\n", argv[1]);
			return (2);
		}

		
		
	}
	return (0);
}

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
