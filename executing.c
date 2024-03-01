#include "shell.h"

/**
 * executing_the_directive - a function that executes the
 * input from buffer.
 * @input: The argument from buffer.
 * @argv: An array of argument.
 * @env: The environment variables.
*/

void executing_the_directive(char *input, char *argv[], char **env)
{
	char *args[10];
	char *path, *shell_identifier;
	int status, nume_argmts;
	pid_t child_pid;

	shell_identifier = argv[0];
	nume_argmts = input_tokenizer(input, args);

	if (nume_argmts == 0)
		return;
	if (handling_builtin_directives(args, nume_argmts, input, env) == 1)
		return;
	path = obtainfile_pathway(args[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Failed to create");
		free(input);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			write(2, shell_identifier, strlen(shell_identifier));
			write(2, ": 1: ", 5);
			write(2, args[0], strlen(args[0]));
			write(2, ": not found\n", 12);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
}
