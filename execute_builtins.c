#include "main.h"

/**
 * execute_builtins - a function for handling the biltins
 * @tokens: the tokens from the argument
 * @num_tokens: the number of tokens
 * @error_info: struct of the error information
 * @line: the line gotten
 * Return: void
*/

int execute_builtins(char **tokens, int num_tokens,
error_h_t *error_info, char *line)
{

	const char *command = *tokens;
	int status = 0;

	if (num_tokens > 0)
	{
		if (_strcmp(command, "cd") == 0)
		{
			cd_command(tokens, error_info);
			return (0);
		}
		else if (_strcmp(command, "env") == 0)
		{
			print_env();
			return (0);
		}
		else if (_strcmp(command, "setenv") == 0)
		{
			_setenv(tokens);
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
	}

	return (-1);
}

