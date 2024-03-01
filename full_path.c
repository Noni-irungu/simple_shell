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
	char *full_path;

	if (beginforwardslash(file_identifier) && access(file_identifier, X_OK) == 0)
	{
		return (strdup(file_identifier));
	}
	if (!path)
	{
		perror("Path not found");
		return (NULL);
	}

	full_path = obtainfile_executable(path, file_identifier);

	if (full_path == NULL)
	{
		write(2, file_identifier, strlen(file_identifier));
		write(2, ": command not found\n", 19);
		return (NULL);
	}

	return (full_path);
}
