#include "shell.h"

/**
 * framework_exit - a function that
 * handles the exit status.
 * @args: The arguments to the function.
 * @input: It checks the status of exit.
 *
 * Return: Status of exit, otherwise (1)
*/

int framework_exit(char **args, char *input)
{
	char *string_status;
	int exit_status, r;

	if (args[1] != NULL)
	{
		exit_status = 0;
		string_status = args[1];

		for (r = 0; string_status[r] != '\0'; r++)
		{
			if (string_status[r] < '0' || string_status[r] > '9')
			{
				handling_the_exit(input, 2);
				return (1);
			}
			exit_status = exit_status * 10 + (string_status[r] - '0');
		}
		handling_the_exit(input, exit_status);
	}
	else
	{
		handling_the_exit(input, 127);
	}
	return (1);
}
