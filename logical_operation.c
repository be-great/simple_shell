#include "main.h"
/**
* handle_and_commands - handle the and commands
* @command: the command
* @error_info: the error info struct
*/
void handle_logical_operators(char *command, error_h_t *error_info)
{
	int num_tokens;

	char *subcommand;

	char **argv;

	int num_subtokens, i;

	char **and_commands;

	int builtins;


	and_commands = split_commands(command, &num_tokens, "&&");
	for (i = 0; i < num_tokens; i++)
	{
		subcommand = and_commands[i];

		if (strstr(subcommand, "||") != NULL)
		{
			handle_or_commands(subcommand, error_info);
		}
		else
		{
			tokenize_command(subcommand, &argv, &num_subtokens, error_info);
			builtins = execute_builtins(argv, num_subtokens, error_info, subcommand,
					and_commands, num_tokens);

			if (builtins != 0)
			{
				search_command(error_info);
			}

			cleanup_memory(argv, num_subtokens, error_info);
			if (error_info->status != 0)
			{
				break;
			}
		}

	}
	free_commands(and_commands, num_tokens);
}
/**
* handle_or_commands- handle the or commands
* @command: the command
* @error_info: the error info struct
*/
void handle_or_commands(char *command, error_h_t *error_info)
{
	int num_tokens, builtins, i;

	char **or_commands;

	char *subcommand;

	char **argv;

	int num_subtokens;

	or_commands = split_commands(command, &num_tokens, "||");
	for (i = 0; i < num_tokens; i++)
	{
		subcommand = or_commands[i];
		tokenize_command(subcommand, &argv, &num_subtokens, error_info);
		builtins = execute_builtins(argv, num_subtokens, error_info, subcommand,
				or_commands, num_tokens);

		if (builtins != 0)
		{
			search_command(error_info);
		}

		cleanup_memory(argv, num_subtokens, error_info);
		if (error_info->status == 0)
		{
			break;
		}
		
	}

	/* Free memory for '||' commands*/
	free_commands(or_commands, num_tokens);
}
