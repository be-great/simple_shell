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
	int i;
	char **env = environ;
	char *new_env;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0
		&& env[i][_strlen(name)] == '=')
		{
			if (overwrite)
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

				env[i] = new_env;

				return (0);
			}
			return (0);
		}

	}

	if (add_environ(env, name, value, i) != 0)
	{
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

	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);


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
		if (_strncmp(env[i], name, _strlen(name)) == 0
		&& env[i][_strlen(name)] == '=')
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
/**
 * *_realloc - function that reallocates a memory block using
 * malloc and free
 * Description: creating realloc function , it resize aready sized pointer
 * @ptr: the pointer
 * @old_size: the old size
 * @new_size: the new size
 * Return: if new_size = old_size return ptr,or null
 * when new_size = 0 and ptr != null
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		ptr = malloc(new_size);

	free(ptr);
	ptr = malloc(new_size);

	if (ptr == NULL)
		return (NULL);
	return (ptr);

}
