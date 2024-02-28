#include "shell.h"

/**
 * handling_the_exit - a function that
 * handles the exit functionality.
 * @input: The input value to handle.
 * @exit_status: The exit status of the code.
*/

void handling_the_exit(char *input, int exit_status)
{
	free(input);
	exit(exit_status);
}
