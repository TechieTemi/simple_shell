#include "shell.h"

/**
 * is_program - verify if a text is executable
 * @p: command to verify
 * Return: program status.
*/

int is_program(char *p)
{
	struct stat buf;

	if ((stat(p, &buf) == 0) && (p[0] == '/' || p[0] == '.'))
		return (1);
	return (0);
}

/**
 * is_builtin - Execute a shell command
 * @line: command from user.
 * @args: Array of arguments for the command
 * @pr_name: programe name.
 * @env: Array containing environment variables
 *
 * Return: Status code indicating the result of the command execution
 */

int is_builtin(char *line, char **args, char *pr_name, char **env)
{
	if (args[0] == NULL)
	{
		/* An empty command was entered */
		return (1);
	}

	if (is_equal(args[0], "cd"))
	{
		return (hsh_cd(args, pr_name));
	}
	else if (is_equal(args[0], "help"))
	{
		return (hsh_help());
	}
	else if (is_equal(args[0], "exit"))
	{
		return (hsh_exit());
	}
	else if (is_equal(args[0], "env"))
	{
		return (print_env(pr_name, env));
	}
	else if (is_program(args[0]))
	{
		return (execnopath(line, args, pr_name, env));
	}
	else
		return (-11);
}

/**
 * execnopath - Launch a process.
 * @line: command from user.
 * @args: Array of arguments for the process
 * @pr_name: programe name.
 * @env: Array containing environment variables
 *
 * Return: Status code indicating the result of the process execution
 */
int execnopath(char *line, char **args, char *pr_name, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, env) == -1)
		{
			print_error(pr_name, args[0], "not found", "");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Error forking */
		print_error(pr_name, " ", "not found", "");
	}
	else
	{
		wait(&status);
		if (status != 0)
			if (!isatty(STDIN_FILENO))
			{
				free(line);
				free(args);
				_exit(2);
			}
	}
	return (1);
}
