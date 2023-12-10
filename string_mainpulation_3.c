#include "main.h"
/**
* pidlen - Function to calculate the number of digits in a pid_t
* @pid: The process ID (pid_t) to calculate the length for
*
* Return: The number of digits in the pid_t
*/
size_t pidlen(pid_t pid)
{
	int count = (pid == 0) ? 1 : 0;

	while (pid != 0)
	{
		pid /= 10;
		count++;
	}
	return (count);
}

/**
* pidToString - Function to convert a pid_t to a string
* @pid: The process ID (pid_t) to convert
* @str: The destination string buffer
* @size: The size of the destination buffer
*
* Convert the pid_t to its string representation and store it in str.
* If the buffer size is insufficient, an error message is printed, and the
* program exits with failure.
*/
void pidToString(pid_t pid, char *str, size_t size)
{
	size_t numDigits = pidlen(pid);
	pid_t temp;
	int i;

	if (size <= numDigits)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	/* Handle the case for 0 separately */
	if (pid == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}

	/* Convert each digit of the pid to a character */
	temp = pid;
	i = numDigits - 1;

	while (temp != 0)
	{
		str[i--] = (temp % 10) + '0';
		temp /= 10;
	}

	str[numDigits] = '\0';
}
