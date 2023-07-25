#include "shell.h"

/**
 * is_equal - This function compares two strings for equality.
 * @str1: 1st param.
 * @str2: 2nd param.
 * Return: true or false.
 */
int is_equal(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (0);
		}
		i++;
	}
	/* If we reach here, then the strings are equal. */
	return (1);
}
