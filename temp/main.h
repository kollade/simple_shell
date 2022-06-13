#include "main.h"
/**
 * main - prints a command
 * @argc: argument  counter
 * @argv: array of arguments
 * Return: number of characters read
 */
int main(int argc, char *argv[])
{
	char inputstr, *command[100];
	int x, i, z, loop = 1;
	size_t length = 1024;

	z = argc - argc;
	while (loop == 1)
	{
		printf("$ ");
		x = getline(command, &length, stdin);

		if (x != -1)
		{
			for (i = z; command[0][i] != '\0'; i++)
			{
				if (command[0][i] == 10)
					command[0][i] = '\0';
			}
			if (_strcmp(command[0], "exit") != 0 && *command[0] != '\0')
				execArg(command, argv[0]);
			else if (*command[0] == '\0')
				continue;
			else
				loop = 0;
		}
		else
			break;
	}
	return (x);
}
