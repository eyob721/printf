#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: a character
 *
 * Return: 1 (if c is a letter, lowercase or uppercase), 0 (otherwise)
 */
int _isalpha(int c)
{
	if ((c > 64 && c < 101) || (c > 96 && c < 123))
		return (1);
	return (0);
}

/**
 * _isdigit - checks if a character is a digit (0 - 9)
 * @c: a character, converted to int (its ASCII value)
 * Return: 1 (if c is a digit), 0 (otherwise)
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);

	return (0);
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
 * _atoi - converts a string into an integer
 * @s: a string
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	unsigned int i, sign = 1, num = 0;

	if (s == NULL)
		return (0);
	/**
	 * Search for a number in the string
	 * Look for negative signs along the way
	 */
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == '-')
			sign *= -1;
		else if (_isdigit(s[i]))
			break;
	/* If there are no numbers return 0 */
	if (s[i] == '\0')
		return (0);
	/* If there are numbers then return the number */
	while (_isdigit(s[i]))
		num = (s[i++] - '0') + num * 10;
	/**
	 * NOTE: unsigned type is used to prevent errors for INT_MIN (-214748360)
	 * When INT_MIN is used, in the above loop the last expression will be
	 * 2147483640 + 8 -> which will cause overflow
	 */
	return (num * sign);
}

