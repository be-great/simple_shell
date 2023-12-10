#include "main.h"
/**
* is_empty_or_whitespace - check if str is empty of just spaces
* @str: the string
* Return: 1 empty 0 not empty
*/
int is_empty_or_whitespace(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))

		{
			return (0);  /* Not empty or whitespace*/
		}
		str++;
	}
	return (1);  /* Empty or whitespace*/
}

/**
* **environ_copy - make a copy of current enviroment
* (printenv)
* Return: return the new enviroment
*/
char **environ_copy()
{
	int env_size = 0, i;

	char **new_env = NULL;

	/* Calculate the size of the environment */
	while (environ[env_size] != NULL)
	{
		env_size++;
	}

	/* Allocate memory for the new environment */
	new_env = malloc((env_size + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	/* Copy the environment */
	for (i = 0; i < env_size; i++)
	{
		new_env[i] = strdup(environ[i]);
		if (new_env[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
	}

	new_env[env_size] = NULL;

	return (new_env);
}
/**
* free_environ_copy - free the new enviroment located
* @env: the enviroment you located
*/
void free_environ_copy(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{

		free(env[i]);
	}
	free(env);
}
/**
* command_exists - check if command exist land
* @command: the command
* @error_info: the error struct
* Return: 0 none exist and 1 existing
*/
int command_exists(char *command, error_h_t *error_info)
{
	if (command == NULL || command[0] == '\0')
	{
		/* Handle invalid command (e.g., print an error message).*/
		printerr(error_info, "not found\n");
		error_info->status = 127;
		return (0);
	}
	if (access(command, F_OK) != -1)
	{
		return (1);
	}
	else
	{
		printerr(error_info, "not found\n");
		error_info->status = 127;
		return (0);
	}
}
/**
 * add_environ - add new enviroment variable
 * @name: the name
 * @value: the value
 * Return: 0 success , -1 Not a success
 */
int add_environ(char *name, char *value)
{
	char *new_env;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
	}
	new_env = malloc(_strlen(name) + _strlen(value) + 2);
	if (new_env == NULL)
	{
		perror("malloc allocation failed");
		return (-1);
	}

	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);

	environ[i] = new_env;
	environ[i + 1] = NULL;

	return (0);
}
