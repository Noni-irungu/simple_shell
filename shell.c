#include "shell.h"

/**
 * main - a function that waits for the program
 * @argc: the argument count.
 * @argv: An array of arguments.
 * @environ: The environment variables.
 *
 * Return: 0 Alawys success
*/

int main(int argc, char *argv[], char **environ)
{
	char *insert_buff;
	(void)argc;

	while (1)
	{
		showing_prompt();
		insert_buff = obtain_user_input();
		executing_the_directive(insert_buff, argv, environ);
		free(insert_buff);
	}

	return (0);
}
