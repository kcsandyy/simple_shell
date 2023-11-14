#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * main - Entry of my shell
 * Return: 0 success
 */

int main(void)
{
	char command[command_len];

	while (1)
	{
		printf("$ ");

		if (fgets(command, command_len, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(0);
			}
			else
			{
				perror("Error reading command");
				exit(1);
			}
		}
		command[strcspn(command, "\n")] = '\0';
		execute_cmd(command);
	}
	return (0);
}
