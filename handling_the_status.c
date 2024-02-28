#include "shell.h"

/**
 * framework_exit - a function that
 * handles the exit status.
 * @argmts: The arguments to the function.
 * @insert: It chaecks the status of exit.
 *
 * Return: Staus of exit, otherwise (-1)
*/

int framework_exit(char **argmts, char *insert)
{
	char *string_status;
	int exit_status;
	int r;

	if (argmts[1] != NULL)
	{
		exit_status = 0;
		string_status = argmts[1];

		for (r = 0; string_status[r] != '\0'; r++)
		{
			if (string_status[r] < '0' || string_status[r] > '9')
			{
				handling_the_exit(insert, 2);
				return (1);
			}
			exit_status = exit_status * 10 + (string_status[r] - '0');
		}
		handling_the_exit(insert, exit_status);
	}
	else
	{
		handling_the_exit(insert, 127);
	}
	return (1);
}
