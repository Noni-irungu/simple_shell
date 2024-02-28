#include "shell.h"

/**
 * executing_the_directive - a function that executes the
 * input from buffer.
 * @insert: The argument from buffer.
 * @argmtsv: An array of argument.
 * @env: The environment variables.
*/

void executing_the_directive(char *insert, char *argmtsv[], char **env)
{
	char *argmts[10];
	char *path, *shell_identifier;
	int status, nume_argmts;
	pid_t child_pid;

	shell_identifier = argmtsv[0];
	nume_argmts = input_tokenizer(insert, argmts);

	if (nume_argmts == 0)
		return;
	if (handling_builtin_directives(argmts, nume_argmts, insert, env) == 1)
	{
		return;
	}
	path = obtainfile_pathway(argmts[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Failure to create");
		free(insert);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(path, argmts, NULL) == -1)
		{
			write(2, shell_identifier, strlen(shell_identifier));
			write(2, ": 1: ", 5);
			write(2, argmts[0], strlen(argmts[0]));
			write(2, ": was not found\n", 16);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
}
