#include "main.h"

/**
 * cd_command - the function to implemen the cd builtin
 * @argv: the arguments received
*/

int cd_command(char **argv)
{
	int dir;
	char *command;
	char *buffer;
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
		long maxPath = pathconf(command, _PC_PATH_MAX);

			if (maxPath == -1)
			{
				perror("pathconf");
				return (-1);
			}
		buffer = malloc((size_t)maxPath + 1);

		if (buffer == NULL)
		{
			perror("malloc");
			return (-1);
		}
		if (strcmp(command, "-") == 0)
		{
			dir = cdDash(buffer, maxPath);
		}
		else
		{
			dir = changeDir(command, buffer, maxPath);
		}
			if (dir != 0)
			{
				free(buffer);
				return (dir);
			}

			free(buffer);
	}
	return (0);
}



int changeDir(char *command, char *buffer, size_t maxPath)
{
	int dir;

	dir = chdir(command);

	if (dir != 0)
	{
		perror("cd");
		free(buffer);
		return (-1);
	}
	else
	{
		if (getcwd(buffer, (size_t)maxPath + 1) == NULL)
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

int cdDash(char *buffer, size_t maxPath)
{
    int dir;
    char *oldpwd;

    oldpwd = getenv("OLDPWD");

    if (oldpwd == NULL)
    {
        fprintf(stderr, "cd: OLDPWD not set\n");
        return -1;
    }

    dir = chdir(oldpwd);

    if (dir != 0)
    {
        perror("cd");
    }
    else
    {
        if (getcwd(buffer, (size_t)maxPath + 1) == NULL)
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
