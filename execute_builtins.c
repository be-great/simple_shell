#include "main.h"

/**
 * initbuiltin - a function for holding the builtins
 * Return: the builtin found
*/
builtin_cmd_t *initbuiltin(void)
{
	static builtin_cmd_t builtin[] = {
		{"cd", cd_command},
		{"exit", exit_cmd},
		{"env", print_env},
		{"setenv", setenv_builtin},
		{"unsetenv", unsetenv_builtin},
		{NULL, NULL}
	};

	return (builtin);
}


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
	char *command = *tokens;
	int builtin_size = NUM_BUILTIN;
	int i, status = 0;
	builtin_cmd_t *builtins = initbuiltin();

	if (num_tokens > 0)
	{
		for (i = 0; i < builtin_size; i++)
		{
			if (_strcmp(command, builtins[i].command_name) == 0)
			{
				if (_strcmp(command, "exit") != 0)
				{
					builtins[i].builtin_func(tokens, error_info);
					return (0);
				}
				else
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
		}
	}
	return (-1);
}
