#include "shell.h"

/**
 * designate_cd - a funtion that handles
 * the cd functionality.
 * @argmts: An array of commands.
 * @nume_argmts: The argument count.
*/

void designate_cd(char **argmts, int nume_argmts)
{
	const char *central_directory;
	const char *preceding_directory;

	central_directory = getenv("HOME");
	preceding_directory = getenv("OLDPWD");
	if (nume_argmts == 1 || strcmp(argmts[1], "~") == 0)
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
	else if (nume_argmts == 2 && strcmp(argmts[1], "-") == 0)
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
		if (chdir(argmts[1]) != 0)
		{
			perror("cd");
		}
	}
}
