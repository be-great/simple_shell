#include "main.h"

/**
* isnumber - check if agiving string is number only
* @numbers: the string to check
* Return: 1 if true 0 if false
*/

int isnumber(char numbers[])
{
	int i = 0;

	if (numbers[0] == '-')
		i = 1;
	while (numbers[i] != '\0')
	{
		if (!isdigit(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}
/**
* _atoi - function that convert a string to an integer.
* @s: the string array
* Return: the number we got
*/

int _atoi(char *s)
{

	int sig = 1;

	unsigned int number = 0;

	/*int i = 0;*/

	while (*s != '\0')
	{
		if (*s == '-')
			sig = sig * -1;
		else if (*s >= '0' && *s <= '9')
		{
			number = (number * 10) + (*s - '0');
		}
		else if (number > 0)
			break;
		s++;
	}
	return (number * sig);
}

/**
* *_strncpy - function that copies a string.
* @dest: destination string
* @src: source string
* @n: number of byte to copy
* Return: the dest pointer
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
	dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/**
* intToString_2 - convert int to string return the buffer
* @number: the number
* Return: the character of string to return
*/
char *intToString_2(int number)
{
	int numDigits;
	int i, temp;
	char *str;

	numDigits = numlen(number);
	str = (char *)malloc((numDigits + 1) * sizeof(char));
	if (str == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	/* Handle the case for 0 separately */
	if (number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	/* Convert each digit of the number to a character */
	temp = number;
	i = numDigits - 1;
	while (temp != 0)
	{
		str[i--] = (temp % 10) + '0';
		temp /= 10;
	}

	str[numDigits] = '\0';

	return (str);
}
/**
* numlen - count the integer number len
* @number: the number
* Return: the number length
*/
int numlen(int number)
{
	int count = 0;

	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
