#include "main.h"

/**
 * cd_command - the function to implemen the cd builtin
 * @argv: the arguments received
*/

void cd_command(char **argv)
{
	int dir;
	char *command;
	char buffer[20000]; /*still looking for a way not to hardcode the buffer size*/

	command = argv[1];

	if (command == NULL || strcmp(command, "-") == 0)
	{
		dir = chdir(getenv("HOME"));

		if (dir != 0)
		{
			perror("cd");
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
