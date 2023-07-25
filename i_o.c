#include "shell.h"

/**
 * read_line_shell - Read a line of input from the user
 *
 * Return: The input line
 */
char *read_line_shell(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t n = getline(&line, &bufsize, stdin);

	if (n == -1) /*Read input from stdin*/
	{
		free(line);
		if (isatty(STDIN_FILENO))
			print_output("\n");
		exit(EXIT_SUCCESS);
	}

	return (line);
}

/**
 * print_output - Print a string to the standard output stream
 *
 * @str: The string to be printed
 */
void print_output(const char *str)
{
	ssize_t len = strcount(str);

	write(STDOUT_FILENO, str, len); /* Write the string to the standard output*/
}

/**
 * print_outputer - Print a string to the standard output stream.
 * @str: The string to be printed
 */
void print_outputer(const char *str)
{
	ssize_t len = strcount(str);

	write(STDERR_FILENO, str, len); /* Write the string to the standard output*/
}
/**
 * print_error - Print a string to the standard error stream
 * @name: name of the program.
 * @cmd: command that caused the error.
 * @ermsg: message to be displated.
 * @badag: bad argument if any.
 */
void print_error(const char *name, const char *cmd, char *ermsg, char *badag)
{
	print_outputer(name); /* Write the string to the standard error*/
	print_outputer(": 1: ");
	print_outputer(cmd);
	print_outputer(": ");
	print_outputer(ermsg);
	print_outputer(badag);
	print_outputer("\n");
}

/**
 * parse_line - Parse the line into arguments.
 * @line: The input line to be parsed
 *
 * Return: An array of arguments
 */

char **parse_line(char *line)
{
	int bufsize = strcount(line);
	int position = 0;
	char **tokens = (char **)malloc(bufsize * sizeof(char *) + 5);
	char *token;

	if (!tokens)
	{
		exit(EXIT_SUCCESS);
	}

	token = strtok(line, LSH_TOK_DELIM); /*Tokenize the input line*/
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, LSH_TOK_DELIM); /*Get the next token*/
	}
	tokens[position] = NULL; /*Set the last element of the array to NULL*/
	return (tokens);
}
