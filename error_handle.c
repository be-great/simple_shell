#include "main.h"

/**
* printerr - print the error
* @error_info:  struct of the error
* @message: the type of error
*/
void printerr(error_h_t *error_info, const char *message)
{
	dprintf(STDERR_FILENO, "%s: %u: %s: %s", error_info->fname,
										error_info->line_count,
										error_info->argv[0],
										message);
}


/**
 * addprinterr - a elping function for printerr
 * @command: the command to print
 * Return: a pointer to the error message
*/
char *addprinterr(char *command)
{
	char error_message[PATH_MAX];

	strcpy(error_message, "can't cd to ");
	strcat(error_message, command);
	strcat(error_message, "\n");
	return (strdup(error_message));
}


/**
 * dirError - a helping function for handling irectory error
 * @command: the command to print
 * @error_info: a memeber of the errro struct
 * @buffer: the buffer to free
 * Return: -1 if the program fails
*/
int dirError(char *command, error_h_t *error_info, char *buffer)
{
	char *message;
		message = addprinterr(command);

		if (errno == EACCES)
		{
			printerr(error_info, message);
		}
		else
		{
			printerr(error_info, message);
		}
		free(message);
		free(buffer);
		return (-1);
}
