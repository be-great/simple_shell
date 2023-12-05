#include "main.h"
/**
* _getenv - get enviroment variable
* @name: name of the variable
* Return: the value of the enviroment variable
*/
char *_getenv(const char *name)
{

	int i;

	/* Iterate through the environment variables */
	for (i = 0; environ[i] != NULL; i++)
	{
		/* Find the position of '=' in the current environment variable */
		char *pos = strchr(environ[i], '=');

		if (pos != NULL)
		{
			/* Calculate the length of the variable name */
			size_t len = pos - environ[i];

			/* Compare the variable name with the provided name */
			if (strncmp(environ[i], name, len) == 0 && name[len] == '\0')
			{
				/* Return the value part of the environment variable */
				return (pos + 1);
			}
		}
	}

	/* Return NULL if the environment variable is not found */
	return (NULL);
}
