#include "main.h"

/**
 * setenv_builtin - the function that handles the setenv builtin
 * @argv: the arguments passed
 * @error_info: the struct for the error
 * Return: 0 if successful, else -1 on failure;
*/
int setenv_builtin(char **argv, error_h_t *error_info)
{
    char **env = environ;
    char *variable, *value;
    int i;

    if (argv[1] == NULL || argv[2] == NULL)
    {
        printerr(error_info, "invalid VARIABLE VALUE\n");
        return (-1);
    }
    variable = argv[1];
    value = argv[2];

    for (i = 0; env[i] != NULL; i++)
    {
        if (strncmp(env[i], variable, strlen(variable)) == 0 && env[i][strlen(variable)] == '=')
        {
            
            if (setenv(variable, value, 1) != 0)
            {
                perror("setenv");
                return (-1);
            }
            return (0);
        }
    }

    if (setenv(variable, value, 0) != 0)
    {
        perror("setenv");
        return (-1);
    }
    return (0);
}

int unsetenv_builtin(char **argv, error_h_t *error_info)
{
    int i;
    char *variable;
    char **env = environ;

    if (argv[1] == NULL)
    {
        printerr(error_info, "invalid VARIABLE\n");
        return (-1);
    }
    variable = argv[1];

    for (i = 0; env[i] != NULL; i++)
    {
        if (strncmp(env[i], variable, strlen(variable)) == 0 && env[i][strlen(variable)] == '=')
        {
            if (unsetenv(variable) != 0)
            {
                perror("unsetenv");
                return (-1);
            }
            return (0);
        }
    }
    return (0);
}
