#include "shell.h"

/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @av: Array containing the command-line arguments
 * @env: Array containing environment variables
 *
 * Return: Exit status of the program
 */

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line, *path, *pathval, *full_path;
	char **line_args;
	int status;

	do {							  /*Enter the shell loop*/
		if (isatty(STDIN_FILENO)) /*Print the shell prompt*/
			print_output("$ ");
		line = read_line_shell();	  /*Read input from the user*/
		line_args = parse_line(line); /*Parse the input into arguments*/
		status = is_builtin(line, line_args, av[0], env);
		if (status == -11)
		{
			path = get_env("PATH=", env);
			pathval = gpval(path);
			full_path = find_program_inpath(line_args[0], pathval);
			free(path); /*Free the memory allocated for the input path*/
			if (full_path != NULL)
			{
				status = execute_shell(full_path, line_args, av[0], env);
				free(full_path);
			}
			else
			{
				print_error(av[0], line_args[0], "not found", "");
				if (!isatty(STDIN_FILENO))
				{
					free(line);		 /*Free the memory allocated for the input line*/
					free(line_args); /*Free the memory allocated for the arguments*/
					_exit(127);
				}
			}
		}
		free(line);		 /*Free the memory allocated for the input line*/
		free(line_args); /*Free the memory allocated for the arguments*/
	} while (status);
	exit(EXIT_SUCCESS);
}
