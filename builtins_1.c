#include "main.h"

int _setenv(char **argv)
int _setenv(char *name, char *value)
{
    int i;
    char *newEnv;
    const char *name, *value;
    char **env = environ;

    if (argv == NULL || argv[1] == NULL || argv[2] == NULL)
    {
        perror("invalid VARIABLE VALUE\n");
        return (-1);
    }

    name = argv[1], value = argv[2];
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

    newEnv = malloc(strlen(name) + strlen(value) + 2);
    if (newEnv == NULL)
    {
        perror("malloc");
        return (-1);
    }
	

    for (i = 0; env[i] != NULL; i++)
    {
        if (strncmp(env[i], name, strlen(name)) == 0 && env[i][strlen(name)] == '=')
        {
            
            strcpy(newEnv, name);
            strcat(newEnv, "=");
            strcat(newEnv, value);

            
            env[i] = newEnv;
			
            
            return 0;
        }
		
    }

    
    
	
	fprintf(stderr, "Error: Environment variable not found\n");
	
    return 0;
}

