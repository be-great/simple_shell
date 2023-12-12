#include "main.h"

#include "main.h"

/**
* printerr - Print an error message to stderr.
* @error_info: Pointer to error information.
* @message: The error message to print.
*/
void printerr(error_h_t *error_info, const char *message)
{
	char buffer[1024];  /* Adjust the buffer size as needed */

	char *fname = error_info->fname;

	int line = error_info->line_count;

	char line_str[1024];

	/* Copy filename to buffer */
	_strcpy(buffer, fname);
	/* Add colon separator */
	_strcat(buffer, ": ");
	/* Convert line number to string */
	intToString(line, line_str);
	/* Add line number to buffer */
	_strcat(buffer, line_str);
	/* Add colon separator */
	_strcat(buffer, ": ");
	/* Add program name to buffer */
	_strcat(buffer, error_info->argv[0]);
	/* Add colon separator */
	_strcat(buffer, ": ");
	/* Add message to buffer */
	_strcat(buffer, message);
	/* Use the write system call to print the message to STDERR_FILENO */
	write(STDERR_FILENO, buffer, _strlen(buffer));
}
/**
 * filerror - handle the file not found error
 * @prname: the program name
 * @msg0: the msg1
 * @fname: the filename you type
 * @msg1: the second msg (NO such file)
 */
void filerror(char *prname, char *msg0, char *fname, char *msg1)
{
	char buffer[1024];

	_strcpy(buffer, prname);
	_strcat(buffer, msg0);
	_strcat(buffer, fname);
	_strcat(buffer, msg1);
	write(STDERR_FILENO, buffer, _strlen(buffer));
}
/**
* addprinterr - a elping function for printerr
* @command: the command to print
* Return: a pointer to the error message
*/
char *addprinterr(char *command)
{
	char error_message[PATH_MAX];

	_strcpy(error_message, "can't cd to ");
	_strcat(error_message, command);
	_strcat(error_message, "\n");
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

