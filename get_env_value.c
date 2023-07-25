#include "shell.h"

/**
 * gpval - get an environment variable.
 * @path: the name of the environment variable.
 *
 * Return: the value of the environment variable.
 */

char *gpval(char *path)
{
	strtok(path, "=");
	return (strtok(NULL, "\0"));
}
