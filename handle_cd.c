#include "shell.h"

/**
 * designate_cd - a funtion that handles
 * the cd functionality.
 * @args: An array of commands.
 * @nume_argmts: The argument count.
*/

void designate_cd(char **args, int nume_argmts)
{
	const char *central_directory;
	const char *preceding_directory;

	central_directory = getenv("HOME");
	preceding_directory = getenv("OLDPWD");
	if (nume_argmts == 1 || strcmp(args[1], "~") == 0)
	{
		if (!central_directory)
		{
			perror("Home environment not set");
			return;
		}
		if (chdir(central_directory) != 0)
		{
			perror("cd");
		}
	}
	else if (nume_argmts == 2 && strcmp(args[1], "-") == 0)
	{
		if (!preceding_directory)
		{
			perror("OLDPWD environment not set");
			return;
		}
		if (chdir(preceding_directory) != 0)
		{
			perror("cd");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
