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
void print_the_env(char **myenv);
void handling_the_exit(char *insert, int exit_status);
int framework_exit(char **argmts, char *insert);
void designate_cd(char **argmts, int nume_argmts);
int handling_builtin_directives(char **argmts, int nume_argmts,
		char *insert, char **myenv);

/* The Execute Functions */
void showing_prompt(void);
char *obtain_user_input(void);
int input_tokenizer(char *insert, char *argmts[]);
void executing_the_directive(char *insert, char *argmtsv[], char **myenv);
int beginforwardslash(const char *strng);
char *obtainfile_executable(char *pathway, char *file_identifier);
char *obtainfile_pathway(char *file_identifier);

/* Handles various symbols */
char *handles_statements(char *insert);
int main(int argc, char *argv[], char **myenv);

#endif
