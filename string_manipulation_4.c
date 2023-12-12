#include "main.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	int i;
	char **env = environ;
	char *new_env;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, strlen(name)) == 0 && env[i][strlen(name)] == '=')
		{
			if (overwrite > 0)
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
			else
			{
				/*do nothing if overwrite is non zero*/
				
				return (0);
				
			}
		}
		
	}

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