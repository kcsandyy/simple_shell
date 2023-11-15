#include "shell.h"

/**
 * find_newline - trims the newline character
 * @str: The string
 * Return: the position of the newline character
 */

size_t find_newline(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/**
 * main - Entry of my shell
 * Return: 0 success
 */

int main(void)
{
	char *command = NULL;
	size_t command_len = 0, input, newline_index;

	while (1)
	{
		_putchar('$');
		_putchar(' ');

		input = getline(&command, &command_len, stdin);
		if (input == (size_t)(-1))
		{
			if (feof(stdin))
			{
				_putchar('\n');
				break;
			}
			else
			{
				perror("Error reading command");
				free(command);
				break;
			}
		}
		newline_index = find_newline(command);
		if (command[newline_index] == '\n')
			command[newline_index] = '\0';

		execute_cmd(command);
	}
	free(command);
	return (0);
}
