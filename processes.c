#include "main.h"
/**
* processes - handle the common code for interactive and non interactive
* mode.
* Description: Tokenize the command, execute with child process,
* and clean up memory.
* @line: the input readed from the user
* @error_info: the error info
*/

void processes(char *line, error_h_t *error_info)
{
	char **argv;

	int num_tokens;
	int builtins;

	tokenize_command(line, &argv, &num_tokens, error_info);
	builtins = execute_builtins(argv, num_tokens, error_info, line);
	if (builtins != 0)
	{
		search_command(error_info);
	}
		cleanup_memory(argv, num_tokens, error_info);
}
