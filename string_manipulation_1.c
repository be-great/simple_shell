#include "main.h"


/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* *_memset - fills some memory with cons byte
* @s: the string to fills
* @b: the byte value
* @n: n bytes to fill
* Return: pointer to the memory area s
*/

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		ptr[i] = b;
	}

	return (ptr);
}

/**
* *_strchr - function locates a character in a string
* @s: string
* @c: character to find
* Return: pointer to first occurence of c
*/

char *_strchr(char *s, char c)
{

	char *result = '\0';

	/* loop and check for char c*/
	do {
		if (*s == c)
		{
			result = s;
			break;
		}
	} while (*s++);

	return (result);
}
/**
* _puts - a function that prints a string, followed by a new line
* @str: the string
*/

void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
/**
* _strdup - Duplicates a string.
* @str: The input string to be duplicated.
*
* Return: A pointer to the duplicated string or NULL on failure.
*/
char *_strdup(char *str)
{
	size_t len;
	char *dup_str;

	/* Check if the input string is NULL */
	if (str == NULL)
	{
		return (NULL);
	}

	/* Calculate the length of the input string */
	len = _strlen(str);

	/* Allocate memory for the new string (including space*/
	/*for the null terminator) */
	dup_str = (char *)malloc(len + 1);

	/* Check if memory allocation is successful */
	if (dup_str == NULL)
	{
		return (NULL);
	}

	/* Copy the content of the input string to the new memory location */
	_strcpy(dup_str, str);

	/* Return the pointer to the duplicated string */
	return (dup_str);
}
