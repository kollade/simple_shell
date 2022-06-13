#include "main.h"
/**
 * cd_exec - changes working directory
 * @command: comand passed
 * Return: 1 on success
 */
int cd_exec(char **command)
{
	char *hold;
	int i, j, k;

	hold = command[1];
	if (hold != NULL)
	{
		i = _strcmp("$HOME", hold);
		j = _strcmp("~", hold);
		k = _strcmp("--", hold);
	}
	if (!hold || !i || !j || !k)
		cd_to_home();
	else if (_strcmp("-", hold) == 0)
		cd_previous();
	else if(_strcmp(".", hold) == 0 || _strcmp("..", hold) == 0)
		cd_dot(command);
	else
		cd_to(command);
	return (1);
}
