#include "main.h"

int _setenv(char **argv)
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

