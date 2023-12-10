#include "main.h"

/**
* countword - Count the number of words in a string.
* @str: The input string.
* @delim: The string containing delimiters.
*
* Return: The number of words.
*/
int countword(char *str, const char *delim)
{

	int count = 0, j;

	int is_delim = 1;

	while (*str != '\0')
	{
		int is_current_char_delim = 0;

		for (j = 0; delim[j] != '\0'; j++)
		{
			if (delim[j] == *str)
			{
				is_current_char_delim = 1;
				break;
			}
		}

		if (is_current_char_delim)
		{
			is_delim = 1;
		}
		else if (is_delim)
		{
			is_delim = 0;
			count++;
		}

		str++;
	}

	return (count);
}


/**
* _strtow - Split a string into words using custom strtok-like function.
* @str: The input string.
* @delim: The string containing delimiters.
*
* Return: Pointer to an array of strings.
*/
char **_strtow(char *str, const char *delim)
{
	char **arr, *temp;
	int i, k = 0, len = 0, words, c = 0, start;
	int is_delim = 1, j;

	while (str[len])
		len++;
	words = countword(str, delim);
	/* Allocate memory for the array of strings */
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	/* Tokenize the string */
	for (i = 0; i <= len; i++)
	{
		if (strchr(delim, str[i]) != NULL || str[i] == '\0')
		{
			if (c)
			{
				start = i - c;
				temp = (char *)malloc(sizeof(char) * (c + 1));
				if (temp == NULL)
				{
					/* Free previously allocated memory*/
					for (j = 0; j < k; j++)
						free(arr[j]);
					free(arr);
					return (NULL);
				}
				/* Copy characters from temp to arr[k]*/
				for (j = 0; j < c; j++)
					temp[j] = str[start + j];
				temp[c] = '\0', arr[k] = temp, k++, c = 0;
			} is_delim = 1;
		}
		else if (is_delim)
			is_delim = 0, c++, start = i;
		else
			c++;
	} arr[k] = NULL;
	return (arr);
}
