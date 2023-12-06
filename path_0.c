#include "main.h"
/**
* search_command - search of the command on the PATH variable
* @error_info: the parameter & return info struct
*/
void search_command(error_h_t *error_info)
{
	char *path = NULL;

	int i, k;

	error_info->path = error_info->argv[0];
	for (i = 0, k = 0; error_info->argv[i]; i++)
		if (!is_delimiter(error_info->argv[i][0], " \t\n"))
			k++;
	if (!k)
		return;

	path = get_path(error_info, _getenv("PATH"), error_info->argv[0]);
	if (path)
	{
		error_info->path = path;
		execute_with_child(error_info);
	}
	else
	{
		if ((isatty(STDIN_FILENO) || _getenv("PATH")
			|| error_info->argv[0][0] == '/') &&
				iscommand(error_info, error_info->argv[0]))
			execute_with_child(error_info);
		/* if command not found*/
		else if (*(error_info->argv[0]) != '\n')
		{
			error_info->status = 127;
			printerr(error_info, "not found\n");

		}
	}
}

/**
* iscommand - determines if a file is an executable command
* @error_info: the error_info struct
* @path: path to the file
*
* Return: 1 if true, 0 otherwise
*/
int iscommand(error_h_t *error_info, char *path)
{
	struct stat st;

	(void)error_info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
* is_delimiter - checks if character is a delimeter or not
* @character: the character to check
* @delimiter: the delimeter to find
* Return: 1 if true, 0 if false
*/
int is_delimiter(char character, char *delimiter)
{
	int i = 0;

	while (delimiter[i])
	{
		if (delimiter[i] == character)
			return (1);
		i++;
	}
	return (0);
}
