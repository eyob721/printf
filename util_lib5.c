#include "main.h"

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

/**
 * _strstr - finds the first occurrence of the substring needle
 * in the string haystack
 * @haystack: a string
 * @needle: a substring
 *
 * Return: pointer to the first occurrence of the substring, NULL otherwise
 */
char *_strstr(char *haystack, char *needle)
{
	char *h = haystack, *n = needle;

	if (haystack != NULL && needle != NULL)
	{
		/* If `needle` is empty, return haystack */
		if (*needle == '\0')
			return (haystack);
		/* Now search for `needle`, in the `haystack` */
		while (*haystack != '\0')
		{
			while (*h != '\0' && *n != '\0')
				if (*(h++) != *(n++))
					break;
			/* If `n` is exhausted then `needle` is a match */
			if (*n == '\0')
				return (haystack);
			/* If `needle` is not a match, move along */
			h = ++haystack;
			/* Move `n` back to the beginning of `needle` */
			n = needle;
		}
	}
	return ('\0');
}

/**
 * _strspn - returns the number of bytes in the initial segment of s which
 * consist only of bytes from accept
 * @s: a string
 * @accept: a prefix substring
 *
 * Return: number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char chr, *a = accept;

	(void)chr;
	if (s != NULL && accept != NULL)
	{
		while (*s != '\0' && *s != ' ')
		{
			/* Check if a character from the string `s` is in `accept` */
			chr = *s;
			while (*a != '\0')
			{
				if (*s == *(a++))
				{
					count++;
					break;
				}
			}
			/* Move to the next character in `s` */
			s++;
			/* Move back `a` to the begnning of `accept` */
			a = accept;
		}
	}
	return (count);
}

/**
 * _strpbrk - locates the first occurrence in the string s of
 * any of the bytes in accept.
 * @s: a string
 * @accept: search key string
 *
 * Return: pointer to the found character in the string s, NULL otherwise
 */
char *_strpbrk(char *s, char *accept)
{
	char chr, *a = accept;

	if (s != NULL && accept != NULL)
	{
		/* Check if a character from the string `s` is in `accept` */
		while (*s != '\0')
		{
			chr = *s;
			while (*a != '\0')
				if (chr == *(a++))
					return (s);
			/* Move to the next character in `s` */
			s++;
			/* Move `a` back to the begnning of `accept` */
			a = accept;
		}
	}
	return ('\0');
}
