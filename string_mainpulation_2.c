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
