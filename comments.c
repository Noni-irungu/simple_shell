#include "shell.h"

/**
 * handles_statements - a function that handles
 * the "#" in input.
 * @input: The input value.
 *
 * Return: Stripped down input.
*/

char *handles_statements(char *input)
{
	char *statement_posit;

	statement_posit = strstr(input, " #");

	if (statement_posit)
	{
		*statement_posit = '\0';
	}

	return (input);
}
