#include "shell.h"

/**
 * designate_cd - a funtion that handles
 * the cd functionality.
 * @args: An array of commands.
 * @nume_argmts: The argument count.
*/

void designate_cd(char **args, int nume_argmts)
{
	const char *cent_dir, *prec_dir;

	cent_dir = getenv("HOME");
	prec_dir = getenv("OLDPWD");
	if (nume_argmts == 1 || strcmp(args[1], "~") == 0)
	{
		if (!cent_dir)
		{
			perror("Home environment not set");
			return;
		}
		if (chdir(cent_dir) != 0)
		{
			perror("cd");
		}
	}
	else if (nume_argmts == 2 && strcmp(args[1], "-") == 0)
	{
		if (!prec_dir)
		{
			perror("OLDPWD environment not set");
			return;
		}
		if (chdir(prec_dir) != 0)
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
