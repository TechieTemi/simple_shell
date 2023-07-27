#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_DELIM " \v\t\r\n\a"

/* Function declarations */
int strcount(const char *str);
char *_strcopy(char *dest, char *src);
char *_strconcat(char *dest, char *src);
void print_outputer(const char *str);
int print_env(char *name, char **env);
char *find_program(char *program);
int is_equal(const char *str1, const char *str2);
char *read_line_shell(void);
char **parse_line(char *line);
int execute_shell(char *full_path, char **args, char *pr_name, char **env);
int launch_process(char *full_path, char **args, char *pr_name, char **env);
int hsh_cd(char **args, char *pr_name);
int hsh_help(void);
int hsh_exit(void);
char *find_program_inpath(char *program_name, char *pathval);
void print_output(const char *str);
void print_error(const char *name, const char *cmd, char *ermsg, char *badag);
char *gpval(char *path);
char *get_env(char *name, char **my_env);
int is_builtin(char *line, char **args, char *pr_name, char **env);
int execnopath(char *line, char **args, char *pr_name, char **env);

#endif
