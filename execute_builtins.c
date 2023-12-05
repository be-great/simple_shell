#include "main.h"

/**
 * execute_builtins - a function for handling the biltins
 * @tokens: the tokens from the argument
 * @num_tokens: the number of tokens
 * Return: void
*/

int execute_builtins(char **tokens, int num_tokens)
{

const char *command;

	command = *tokens;

	if (num_tokens > 0)
	{
		switch (command[0])
		{
			case 'c':
			if (strcmp(command, "cd") == 0)
			{
				cd_command(tokens);
				return (0);
			}
			break;

			case 'e':
			if (strcmp(command, "env") == 0)
			{
				print_env();
				return (0);
			}
			break;

			default:
			/*working on the error info*/
			return (1);
		}
	}

	return (-1);
}



