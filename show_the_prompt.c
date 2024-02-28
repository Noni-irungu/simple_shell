#include "shell.h"

/**
 * showing_prompt - A function that shows
 * the prompt to the user.
*/

void showing_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Proto_Shell$$ ", 14);
	}
}
