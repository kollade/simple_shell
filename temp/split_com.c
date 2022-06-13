#include "main.h"
/**
 * split_space - splits commands from arguments
 * @str: stored string from stdin
 * @par: array  of commands
 */
void split_space(char *str, char **par)
{
	int i = 0;
	char *piece;
	piece = strtok(str, " ");

	for (i = 0; piece != NULL && i < MAXLIST; i++)
	{
		par[i] = piece;
		piece = strtok(NULL, " ");
	}
	par[i] = NULL;
}
