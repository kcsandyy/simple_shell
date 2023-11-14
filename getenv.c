#include "shell.h"

/**
 * execute_cmd - Get the value of an environment variable
 * and handles some built-in's commands
 * @name: The name of the environment variable
 * Return: Nothing
 */

void execute_cmd(char *name)
{
	char **env = environ;

	if (strcmp(name, "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else if (strcmp(name, "exit") == 0)
		exit(0);
	else if (strcmp(name, "cd") == 0)
	{
		if (chdir(name) == -1)
		{
			perror("Error: Directory not found");
			exit(1);
		}
	}
	else
	{
		execute_external_cmd(name);
	}
}
