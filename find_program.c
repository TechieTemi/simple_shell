#include "shell.h"

/**
 * find_program_inpath - search for a program in path.
 * @p: name of program to be searched for.
 * @pathval: PATH value.
 * Return: program and path if found or NULL.
 */

char *find_program_inpath(char *p, char *pathval)
{
	int len;
	struct stat buf;
	char *full_path;
	/* Get the PATH environment variable */
	char *directory = strtok(pathval, ":");
	size_t program_name_len = strcount(p);

	if ((stat(p, &buf) == 0) && (p[0] == '/' || p[0] == '.'))
	{
		return (p);
	}
	if (pathval == NULL)
		return (NULL);
	len = strcount(directory) + 1 + program_name_len + 50;
	/* Allocate memory for the full path */
	full_path = (char *)malloc((len * sizeof(char)));
	/* Loop through each directory in PATH */
	while (directory != NULL)
	{
		/* Construct the full path */
		_strcopy(full_path, directory);
		_strconcat(full_path, "/");
		_strconcat(full_path, p);
		/* Check if the program exists at the constructed path */
		if (stat(full_path, &buf) == 0)
		{
			return (full_path);
		}

		directory = (strtok(NULL, ":"));
		/* Move to the next directory in PATH */
	}
	free(full_path);
	/* Free the allocated memory if the program was not found */
	return (NULL);
	/* Return NULL if the program was not found */
}
