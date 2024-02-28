#include "shell.h"

/**
 * handling_builtin_directives - a function that handles
 * all of the builtin directives.
 * @args: The arguments to the builtin directives.
 * @nume_argmts: The number of arguments.
 * @input: Input directive.
 * @env: The environment variables.
 *
 * Return: 1 on (success) and (0) if not successful
*/

int handling_builtin_directives(char **args, int nume_argmts,
		char *input, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (framework_exit(args, input));
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		designate_cd(args, nume_argmts);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_the_env(env);
		return (1);
	}

	return (0);
}
