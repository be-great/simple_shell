#include "main.h"

int _setenv(char *name, char *value)
{
	int i;
	char *newEnv;

	for (i = 0; environ[i] != NULL; i++)
	{
		/* TODO: wirte the funciton strncmp from scratch*/
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
				environ[i][strlen(name)] == '=')
		{
				newEnv = malloc(strlen(name) + strlen(value) + 2);
				if (newEnv == NULL)
				{
					perror("malloc");
					return (-1);
				}

				_strcpy(newEnv, name);
				_strcat(newEnv, "=");
				_strcat(newEnv, value);

				free(environ[i]);
				environ[i] = newEnv;
				print_env();
				return (0);

			}
		}
	add_environ(name, value);
	print_env();

	return (0);
}