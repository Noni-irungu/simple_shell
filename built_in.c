#include "shell.h"

/**
 * handling_builtin_directives - a function that handles
 * all of the builtin directives.
 * @argmts: The arguments to the builtin directives.
 * @nume_argmts: The number of arguments.
 * @insert: Input directive.
 * @myenv: The environment variables.
 *
 * Return: 1 on (success) and (0) if not successful
*/

int handling_builtin_directives(char **argmts, int nume_argmts,
		char *insert, char **myenv)
{
	if (strcmp(argmts[0], "exit") == 0)
	{
		return (framework_exit(argmts, insert));
	}
	else if (strcmp(argmts[0], "cd") == 0)
	{
		designate_cd(argmts, nume_argmts);
		return (1);
	}
	else if (strcmp(argmts[0], "myenv") == 0)
	{
		print_the_env(myenv);
		return (1);
	}

	return (0);
}
