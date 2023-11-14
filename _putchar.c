#include "shell.h"

/**
 * _putchar - prints a character
 * @c: The character
 * Return: 0 success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
