#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line
 * @str: a string
 *
 * Return: void
 */
void _puts(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
			_putchar(*(str++));
		_putchar('\n');
	}
}

/**
 * _islower - checks for lowercase character
 *
 * @c: character to be checked
 * Return: 1 (if @c is lowercase character),or 0 (otherwise)
 */
int _islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

/**
 * _isupper - checks if a character is an UPPERCASE character
 * @c: a character, converted to int (its ASCII value).
 * Return: 1 (if c is uppercase), 0 (otherwise)
 */
int _isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);

	return (0);
}

