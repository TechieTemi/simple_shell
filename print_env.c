#include "shell.h"

/**
 * print_env - prints environment variables
 * @name: programe name
 * @env: list of environment variables.
 *
 * Return: status
 */

int print_env(char *name, char **env)
{
	int i;

	if (env != NULL)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			print_output(env[i]);
			print_output("\n");
		}
		return (1);
	}
	print_error(name, "env", "not found", "");
	return (2);
}
