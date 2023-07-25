#include "shell.h"

/**
 * strcount - This function counts the number of characters in a string.
 * @str: string to be counted.
 * Return: number of chars counted.
 */

int strcount(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
