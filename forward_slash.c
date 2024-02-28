#include "shell.h"

/**
 * beginforwardslash - A function that checks
 * if the file starts with a "/".
 * @strng: The filename to check.
 *
 * Return: 0 if yes, 1 if no
*/

int beginforwardslash(const char *strng)
{
	if (strng != NULL || strng[0] == '/')
	{
		return (1);
	}

	return (0);
}
