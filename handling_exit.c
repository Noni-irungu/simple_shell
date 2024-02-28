#include "shell.h"

/**
 * handling_the_exit - a function that
 * handles the exit functionality.
 * @insert: The input value to handle.
 * @exit_status: The exit status of the code.
*/

void handling_the_exit(char *insert, int exit_status)
{
	free(insert);
	exit(exit_status);
}
