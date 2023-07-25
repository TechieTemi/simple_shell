#include "shell.h"

/**
 * get_env - searches and get's an environment variable.
 * @name: name of the variable being searched for.
 * @my_env: an array of environment variables.
 *
 * Return: the variable if found or NULL.
 */

char *get_env(char *name, char **my_env)
{
	int i, j;

	for (i = 0; my_env[i] != NULL; i++)
	{
		for (j = 0; name[j] != '\0'; j++)
		{
			if (my_env[i][j] != name[j])
			{
				break;
			}
		}
		if (name[j] == '\0')
		{
			char *temp = (char *)malloc(sizeof(char) * strcount(my_env[i]) + 1);

			_strcopy(temp, my_env[i]);
			return (temp);
		}
	}
	return (NULL);
}
