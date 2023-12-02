#include "main.h"

/**
* main - Entry point
* @argc: number of argument passed
* @argv: argument vector of string
* Return: 0 Always (Success)
*/
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    error_h_t error_info;

    (void)argc;  /* Suppress unused parameter warning*/


    /* Initialize error_info structure */
    memset(&error_info, 0, sizeof(error_h_t));

    /* Set filename */
    error_info.fname = argv[0];

    /* Non-interactive mode */
    if (!isatty(STDIN_FILENO))
	{
        while ((read = getline(&line, &len, stdin)) != -1)
		{
			if (is_empty_or_whitespace(line))
			{
                /* Skip processing for empty/whitespace lines*/
                continue;
            }
            processes(line, &error_info);
            if (error_info.status != 0)
                return (error_info.status);
        }

        if (feof(stdin))
		{
            /* End of file reached, cleanup */
            free(line);
            exit(EXIT_SUCCESS);
        }
		else
		{
            perror("getline");
            free(line);
            exit(EXIT_FAILURE);
        }
    }
    /* Interactive mode */
    else {
        while (1)
		{
            printf("$ ");
            read = getline(&line, &len, stdin);

            if (read == -1)
			{
                /* Check for end of file */
                if (feof(stdin))
                    break;
                else
				{
                    perror("getline");
                    free(line);
                    exit(EXIT_FAILURE);
                }
            }
		
            processes(line, &error_info);
            if (error_info.status != 0)
                return (error_info.status);


        }

        free(line);
    }

    return (error_info.status);
}
