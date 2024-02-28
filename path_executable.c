#include "shell.h"

/**
 * obtainfile_executable - a function that obtains
 * the executable path of a file.
 * @pathway: The full path variable.
 * @file_identifier: The executable file.
 *
 * Return: The full path to the executable file.
*/

char *obtainfile_executable(char *pathway, char *file_identifier)
{
	char *pathway_copy;
	char *di_token;
	struct stat file_pathway;
	char *path_buf = NULL;

	pathway_copy = strdup(pathway);
	di_token = strtok(pathway_copy, ":");

	while (di_token)
	{
		if (path_buf)
		{
			free(path_buf);
			path_buf = NULL;
		}
		path_buf = malloc(strlen(di_token) + strlen(file_identifier) + 2);

		if (!path_buf)
		{
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(path_buf, di_token);
		strcat(path_buf, "/");
		strcat(path_buf, file_identifier);
		strcat(path_buf, "\0");

		if (stat(path_buf, &file_pathway) == 0 && access(path_buf, X_OK) == 0)
		{
			free(pathway_copy);
			return (path_buf);
		}
		di_token = strtok(NULL, ":");
	}
	free(pathway_copy);
	if (path_buf)
	{
		free(path_buf);
	}
	return (NULL);
}
