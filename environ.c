#include "shell.h"

/**
 * print_the_environment - a function that prints
 * the environment variables.
 * @myenv: the arguments
*/

void print_the_env(char **myenv)
{
	while (*myenv != NULL)
	{
		write(1, *myenv, strlen(*myenv));
		write(1, "\n", 1);
		myenv++;
	}
}
