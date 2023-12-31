#include "shell.h"

/**
 * _strcopy - copies the string pointed to by src, including \0.
 * @src: pointer.
 * @dest: pointer.
 * Return: the pointer to dest.
 */

char *_strcopy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
