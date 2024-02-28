#include "shell.h"

/**
 * obtainfile_pathway - A function that gets the
 * full path of file.
 * @file_identifier: The argument name.
 *
 * Return: The full path argument to file.
*/

char *obtainfile_pathway(char *file_identifier)
{
	char *path = getenv("PATH");
	char *direct_pathway;

	if (beginforwardslash(file_identifier) && access(file_identifier, X_OK) == 0)
	{
		return (strdup(file_identifier));
	}
	if (!path)
	{
		perror("Path not found");
		return (NULL);
	}

	direct_pathway = obtainfile_executable(path, file_identifier);

	if (direct_pathway == NULL)
	{
		write(2, file_identifier, strlen(file_identifier));
		write(2, ": command not found\n", 19);
		return (NULL);
	}

	return (direct_pathway);
}
