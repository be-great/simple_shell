#include "main.h"
/**
* processes - handle the common code for interactive and non interactive
* mode.
* Description: Tokenize the command, execute with child process,
* and clean up memory.
* @line: the input readed from the user
*/

void processes(char *line)
{
	char **tokens;
	int num_tokens;

	tokenize_command(line, &tokens, &num_tokens);
	execute_with_child(tokens);
	cleanup_memory(tokens, num_tokens);
}
