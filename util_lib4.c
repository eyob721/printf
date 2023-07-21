#include "main.h"

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
 * _strcpy - copies the string src to dest, including the null character.
 * @src: source string
 * @dest: destination string
 *
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest != NULL && src != NULL)
	{
		while (*src != '\0')
			dest[i++] = *(src++);
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes from source
 *
 * Return: destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	if (dest != NULL && src != NULL)
	{
		for (i = 0; src[i] != '\0' && i < n; i++)
			dest[i] = src[i];
		while (i < n)
			dest[i++] = '\0';
	}
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: destination string
 */
char *_strcat(char *dest, char *src)
{
	char *d = dest;

	if (dest != NULL && src != NULL)
	{
		while (*d != '\0')
			d++;
		while (*src != '\0')
			*(d++) = *(src++);
		*d = '\0';
	}
	return (dest);
}

/**
 * _strncat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: number of bytes from source
 *
 * Return: destination string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	if (dest != NULL && src != NULL)
	{
		while (dest[i] != '\0')
			i++;
		while (j < n && src[j] != '\0')
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	return (dest);
}

