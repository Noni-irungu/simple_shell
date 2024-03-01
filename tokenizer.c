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
	int cnt;
	char *di_token;

	cnt = 0;
	di_token = strtok(input, " \n");

	while (di_token)
	{
		args[cnt] = di_token;
		di_token = strtok(NULL, " \n");
		cnt++;
	}

	args[cnt] = NULL;
	return (cnt);
}
