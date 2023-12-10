#include "main.h"

/**
 * _strlen - function to check length of string
 * @str: string to check
 * Return: the length of the string
*/

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}


/**
 * _strcpy - a function for copying one string into another
 * @dest: the destination string
 * @src: the string to copy from
 * Return: the copied string
*/

char *_strcpy(char *dest, char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - a function to concantonate a string
 * @dest: the destination string
 * @src: the source string
 * Return: the concantonated string
*/

char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int src_pos = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	while (src[src_pos] != '\0')
	{
		dest[dest_len] = src[src_pos];
		dest_len++;
		src_pos++;
	}

	dest[dest_len] = '\0';

	return (dest);
}

/**
 * _strcmp - a function that compares two string
 * @str1: first string to compare
 * @str2: second string to compare
 * Return: 0 if successsful, else difference of both strings
*/

int _strcmp(const char *str1, const char *str2)
{
	while ((*str1 && *str2) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
* intToString - convert integer to string
* @number: the number
* @buffer: the buffer
*/
void intToString(int number, char *buffer)
{
	char temp[1024];  /* Adjust the size as needed */
	int i = 0;

	/* Handle negative numbers */
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}

	/* Handle the case when the number is 0 */
	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = '\0';
		return;
	}

	/* Temporary buffer to store the reversed string */
	/* Extract digits and store them in the temporary buffer */
	while (number > 0)
	{
		temp[i++] = '0' + (number % 10);
		number /= 10;
	}

	/* Reverse the temporary buffer and copy it to the output buffer */
	while (--i >= 0)
	{
		*buffer++ = temp[i];
	}

	/* Null-terminate the string */
	*buffer = '\0';
}
