#include "main.h"
/**
* get_path -  Get the path of a enviroment variable
* @error_info: the info of the error
* @path_var: the path value
* @thecommand: the command to check
* Return: the full path of the command
*/
char *get_path(error_h_t *error_info, char *path_var, char *thecommand)
{
	int i = 0, j = 0;

	char *path;

	if (!path_var)
		return (NULL);
	if ((strlen(thecommand) > 2) && beginwith(thecommand, "./"))
	{
		if (iscommand(error_info, thecommand))
			return (thecommand);
	}
	while (1)
	{
		if (!path_var[i] || path_var[i] == ':')
		{
			path = remove_semcolon(path_var, j, i);
			if (!*path)
				strcat(path, thecommand);
			else
			{
				strcat(path, "/");
				strcat(path, thecommand);
			}
			if (iscommand(error_info, path))
				return (path);
			if (!path_var[i])
				break;
			j = i;
		}
		i++;
	}
	return (NULL);
}

/**
* beginwith - checks if the str2 starts with str1
* @str1: string one
* @str2: string two
* Return: next char of str2 or NULL
*/
char *beginwith(const char *str1, const char *str2)
{
	int i = 0, j = 0;

	while (str2[i])
	{
		if (str2[i] != str1[j])
			return (NULL);
		i++, j++;
	}
	return ((char *)&str1[j]);
}
/**
* remove_semcolon - remove the ':' from the strin
* @path_var: the PATH string
* @start: starting index
* @stop: stopping index
* Return: the string without the ':'
*/
char *remove_semcolon(const char *path_var, int start, int stop)
{
	static char buffer[1024];
	int i = 0, j = 0;

	for (j = 0, i = start; i < stop; i++)
		if (path_var[i] != ':')
			buffer[j++] = path_var[i];
	buffer[j] = 0;
	return (buffer);
}
