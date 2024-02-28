#include "shell.h"

/**
 * input_tokenizer - Afunctin that tokenizes
 * the input of strings.
 * @insert: The argument input.
 * @argmts: An array of strings.
 *
 * Return: The number of items tokenized
*/

int input_tokenizer(char *insert, char *argmts[])
{
	int enumerate;
	char *di_token;

	enumerate = 0;
	di_token = strtok(insert, " \n");

	while (di_token)
	{
		argmts[enumerate] = di_token;
		di_token = strtok(NULL, " \n");
		enumerate++;
	}

	argmts[enumerate] = NULL;
	return (enumerate);
}
