#include "shell.h"

/**
 * print_the_environ - a function that prints
 * the environment variables.
 * @environ: the arguments
*/

void print_the_environ(char **environ)
{
	while (*environ != NULL)
	{
		write(1, *environ, strlen(*environ));
		write(1, "\n", 1);
		environ++;
	}
}
