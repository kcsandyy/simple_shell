#include "shell.h"

/**
 * execute_cmd - Get the value of an environment variable
 * and handles some built-in's commands
 * @name: The name of the environment variable
 * Return: Nothing
 */

void execute_cmd(char *name)
{
	char *dir, *args[2];
	char **env = environ;

	if (_strcmp(name, "env") == 0)
	{
		while (*env)
		{
			_puts(*env);
			env++;
		}
	}
	else if (_strcmp(name, "exit") == 0)
		exit(0);
	else if (_strcmp(name, "cd") == 0)
	{
		dir = name + 3;
		if (chdir(dir) == -1)
		{
			perror("Error: Directory not found");
			exit(1);
		}
	}
	else
	{
		args[0] = name;
		args[1] = NULL;

		execute_external_cmd(args[0]);
	}
}
