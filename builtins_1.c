#include "main.h"

int _setenv(const char *name, const char *value)
{
	int i;
	char *newEnv;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
				newEnv = malloc(strlen(name) + strlen(value) + 2);
				if (newEnv == NULL)
				{
					perror("malloc");
					return(-1);
				}
				
				strcpy(newEnv, name);
				strcat(newEnv, "=");
				strcat(newEnv, value);

				free(environ[i]);
				environ[i] = newEnv;
				printenv();
				return (0);

			}
		}
	add_environ(name, value);
	print_env();

	return (0);
}