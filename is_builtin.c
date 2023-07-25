#include "shell.h"

/**
 * is_builtin - Execute a shell command
 * @args: Array of arguments for the command
 * @pr_name: programe name.
 * @env: Array containing environment variables
 *
 * Return: Status code indicating the result of the command execution
 */

int is_builtin(char **args, char *pr_name, char **env)
{
	if (args[0] == NULL)
	{
		/* An empty command was entered */
		return (1); /*1 was here before*/
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
	else
		return (-11);
}
