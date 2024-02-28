#include "shell.h"

/**
 * obtain_user_input - a function that reads
 * the input from its users.
 *
 * Return: The character variable to the program
*/

char *obtain_user_input(void)
{
	char *insert_buff;
	size_t buffer_size;
	ssize_t nosread;

	insert_buff = NULL;
	buffer_size = 0;
	nosread = getline(&insert_buff, &buffer_size, stdin);

	if (nosread == -1)
	{
		free(insert_buff);
		exit(0);
	}

	insert_buff = handles_statements(insert_buff);

	return (insert_buff);
}
