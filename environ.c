#include "shell.h"

/**
 * print_the_env - a function that prints
 * the environment variables.
 * @env: the arguments
*/

void print_the_env(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}
