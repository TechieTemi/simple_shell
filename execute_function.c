#include "shell.h"

/**
 * execute_shell - Execute a shell command
 * @full_path: full path to the prgram to be executed
 * @args: Array of arguments for the command
 * @pr_name: programe name.
 * @env: Array containing environment variables
 *
 * Return: Status code indicating the result of the command execution
 */
int execute_shell(char *full_path, char **args, char *pr_name, char **env)
{
	return (launch_process(full_path, args, pr_name, env));
}

/**
 * launch_process - Launch a process
 * @full_path: full path to the prgram to be executed
 * @args: Array of arguments for the process
 * @pr_name: programe name.
 * @env: Array containing environment variables
 *
 * Return: Status code indicating the result of the process execution
 */
int launch_process(char *full_path, char **args, char *pr_name, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(full_path, args, env) == -1)
		{
			print_error(pr_name, full_path, "not found", "");
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
				free(full_path);
				free(args);
				_exit(2);
			}
	}
	return (1);
}

/**
 * hsh_cd - Change directory
 * @args: Array of arguments for the command
 * @pr_name: programe name.
 *
 * Return: Status code indicating the result of the command execution
 */
int hsh_cd(char **args, char *pr_name)
{
	if (args[1] == NULL)
	{
		if (chdir("/") != 0)
		{
			print_error(pr_name, "", "not found", "");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			print_error(pr_name, "cd", "can't cd to ", args[1]);
		}
	}
	return (1);
}

/**
 * hsh_help - Help command.
 * Return: Status code indicating the result of the command execution
 */
int hsh_help(void)
{
	print_output("Boniface Obidike and Dorcas Temitope HSH\n");
	print_output("Type program names and arguments, and hit enter.\n");
	print_output("The following are built-in:\n");
	print_output("  cd\n");
	print_output("  help\n");
	print_output("  exit\n");
	print_output("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * hsh_exit - Exit command.
 * Return: Status code indicating the result of the command execution.
 */
int hsh_exit(void)
{
	return (0);
}
