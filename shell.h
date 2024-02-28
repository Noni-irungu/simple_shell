#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

/* The Builtin Functions */
void print_the_env(char **env);
void handling_the_exit(char *input, int exit_status);
int framework_exit(char **args, char *input);
void designate_cd(char **args, int nume_argmts);
int handling_builtin_directives(char **args, int nume_argmts,
		char *input, char **env);

/* The Execute Functions */
void showing_prompt(void);
char *obtain_user_input(void);
int input_tokenizer(char *input, char *args[]);
void executing_the_directive(char *input, char *argv[], char **env);
int beginforwardslash(const char *strng);
char *obtainfile_executable(char *path, char *file_identifier);
char *obtainfile_pathway(char *file_identifier);

/* Handles various symbols */
char *handles_statements(char *input);
int main(int argc, char *argv[], char **env);

#endif
