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
	char **tokens;
	int num_tokens;
	int builtins;

	tokenize_command(line, &tokens, &num_tokens, error_info);

	builtins = execute_builtins(tokens, num_tokens);

	if (builtins != 0)
	{
		execute_with_child(tokens, error_info);
	}
		cleanup_memory(tokens, num_tokens);

}
