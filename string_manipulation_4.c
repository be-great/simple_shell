#include "main.h"

/**
 * _strncmp - function for comapring to strings based on number of char
 * @str1: the first string
 * @str2: the second string
 * @n: the maximum number of char
 * Return:  0 if successsful, else difference of both strings
*/

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
	{
		return (0);
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _setenv - custom setenv function
 * @name: the variable
 * @value: the value
 * @overwrite: the number passed
 * Return: 0 or -1
*/
int _setenv(char *name, char *value, int overwrite)
{
	int i = 0;
	char **env = environ;
	char *new_env;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	while (env[i])
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0 && env[i][_strlen(name)] == '=')
		{
			if (overwrite > 0)
			{
				new_env = malloc(_strlen(name) + _strlen(value) + 2);
				if (new_env == NULL)
				{
					perror("malloc allocation failed");
					return (-1);
				}
				_strcpy(new_env, name);
				_strcat(new_env, "=");
				_strcat(new_env, value);

				free_environ_copy(env);
				env[i] = new_env;

				return (0);
			}
			return (0);
		}
		i++;

	}

	if (add_environ(env, name, value, i) != 0)
	{
		free_environ_copy(env);
		return (-1);
	}
	return (0);
}


/**
 * add_environ - add new enviroment variable
 * @env: the environ
 * @name: the name
 * @value: the value
 * @i: the index
 * Return: 0 success , -1 Not a success
 */
int add_environ(char **env, char *name, char *value, int i)
{
	char *new_env;

	new_env = malloc(strlen(name) + strlen(value) + 2);
	if (new_env == NULL)
	{
		perror("malloc allocation failed");
		return (-1);
	}

	strcpy(new_env, name);
	strcat(new_env, "=");
	strcat(new_env, value);

	
	env[i] = new_env;
	env[i + 1] = NULL;

	
	return (0);
}


/**
 * _unsetenv - a custom unsetenv function for unsetting environment variable
 * @name: the name of the variable
 * Return: 0 for success -1 for failure
*/

int _unsetenv(char *name)
{
	int i = 0, j;
	char **env = environ;

	if (name == NULL)
	{
		return (-1);
	}

	while (env[i])
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0 && env[i][_strlen(name)] == '=')
		{
			j = i;
			while (env[j] != NULL)
			{
				env[j] = env[j + 1];
				j++;
			}
			return (0);
		}
		i++;
	}
	return (-1);
}
