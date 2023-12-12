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
int _setenv(const char *name, const char *value, int overwrite)
{
	int i;
	char **env = environ;
	char *new_env;

	if (!name || !value)
	{
		return (-1);
	}
	while (env[i])
	{
		if (strncmp(env[i], name, strlen(name)) == 0)
		{
			if (overwrite)
			{
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

				return (0);
			}
			return (0);
		}
		i++;

	}

	if (add_environ(env, name, value, i) != 0)
	{
		return (-1);
	}
	return (0);
}
