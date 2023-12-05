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
*/

void exit_cmd(char **argv, error_h_t *error_info)
{
	char *command = argv[0];

	if (command != NULL)
	{
		error_info->status = (EXIT_SUCCESS);
	}
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