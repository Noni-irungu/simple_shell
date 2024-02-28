#include "shell.h"

/**
 * input_tokenizer - Afunctin that tokenizes
 * the input of strings.
 * @input: The argument input.
 * @args: An array of strings.
 *
 * Return: The number of items tokenized
*/

int input_tokenizer(char *input, char *args[])
{
	int enumerate;
	char *di_token;

	enumerate = 0;
	di_token = strtok(input, " \n");

	while (di_token)
	{
		args[enumerate] = di_token;
		di_token = strtok(NULL, " \n");
		enumerate++;
	}

	args[enumerate] = NULL;
	return (enumerate);
}
