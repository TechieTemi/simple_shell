#include "shell.h"

/**
 * _strconcat - This function concatenates two strings.
 * @dest: 1st param.
 * @src: 2nd param.
 * Return: concatinated string.
 */

char *_strconcat(char *dest, char *src)
{
	int i;

	/* Get the length of the destination string. */
	int dest_len = strcount(dest);

	/* Get the length of the source string. */
	int src_len = strcount(src);

	/* Iterate over the source string, copying each char to the destination.*/
	for (i = 0; i < src_len; i++)
	{
		dest[dest_len + i] = src[i];
	}

	/* Add a null terminator to the end of the destination string. */
	dest[dest_len + src_len] = '\0';

	/* Return the destination string. */
	return (dest);
}
