#include "main.h"

/**
 * execute_builtins - a function for handling the biltins
 * @tokens: the tokens from the argument
 * @num_tokens: the number of tokens
 * @error_info: struct of the error information
 * Return: void
*/

int execute_builtins(char **tokens, int num_tokens, error_h_t *error_info, char *line)
{

	const char *command;
	int status = 0;

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
			else if (strcmp(command, "exit") == 0)
			{
				status = exit_cmd(tokens, error_info);
				error_info->status = status;
				if (status != 2)
				{
					cleanup_memory(tokens, num_tokens, error_info);
					free(line);
					exit(status);
				}
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



