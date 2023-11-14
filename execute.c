#include "shell.h"

/**
 * execute_external_cmd - executes a command
 * @cmd: The command to be executed
 * Return: -1 on failure else returns nothing on success
 */

void execute_external_cmd(char *cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execlp(cmd, cmd, NULL) == -1)
		{
			perror("Error");
		}
		exit(1);
	}
	else if (pid == -1)
	{
		perror("Error: fork failed");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
