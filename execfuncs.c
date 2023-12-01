#include "main.h"

/**
 * execmd - function to execute the tokenized commands
 * @argv: an array of strings for the commands and arguments
*/

void execmd(char **argv)
{
	char *command_passed = NULL;

	if (*argv != NULL)
	{
		/*set cmmand to the actual command passsed*/
		command_passed = argv[0];
	}

	/*check if execution fails*/
	if (execve(command_passed, argv, NULL) == -1)
	{
		perror("Error");
	}
}

/**
 * get_location - a function to get the path for the execve function
 * @command: the command to get the full path
*/

