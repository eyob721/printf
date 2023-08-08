#include "printf.h"

/**
 * _isdigit - checks if a character is a digit (0 - 9)
 * @c: a character, converted to int (its ASCII value)
 * Return: 1 (if c is a digit), 0 (otherwise)
 */
int _isdigit(int c)
{
	return (c > 47 && c < 58);
}

/**
 * _abs - computes the absolute value of an integer
 * @x: an integer
 *
 * Return: the absolute value of x
 */
int _abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/**
 * _strlen - returns the length of a string
 * @s: a string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s != NULL && *(s++) != '\0')
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: less than, greater than or equal to zero
 */
int _strcmp(char *s1, char *s2)
{
	if (s1 != NULL && s2 != NULL)
		while (*s1 != '\0' || *s2 != '\0')
		{
			if (*s1 != *s2)
				return (*s1 - *s2);
			s1++, s2++;
		}
	return (0);
}

/**
 * _strchr - locates a character in a string
 * @s: a string
 * @c: a character
 *
 * Return: pointer to the character in the string, or NULL otherwise
 */
char *_strchr(char *s, char c)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			if (*s == c)
				return (s);
			s++;
		}
		/**
		 * If `c` is also '\0',
		 * then return a pointer to the '\0' character in the string
		 */
		if (c == '\0')
			return (s);
	}
	return ('\0');
}

