#include "shell.h"

/**
 * handles_statements - a function that handles
 * the "#" in input.
 * @insert: The input value.
 *
 * Return: Stripped down input.
*/

char *handles_statements(char *insert)
{
	char *statement_posit;

	statement_posit = strstr(insert, "#");

	if (statement_posit)
	{
		*statement_posit = '\0';
	}

	return (insert);
}
