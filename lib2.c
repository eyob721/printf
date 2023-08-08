#include "printf.h"

/**
 * _memset - fills the first n bytes of memory pointed by s
 * with a constant byte b
 * @s: memory location
 * @n: number of bytes
 * @b: a constant byte
 *
 * Return: memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; s != NULL && i < n; i++)
		s[i] = b;

	return (s);
}

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes
 *
 * Return: destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	if (dest != NULL && src != NULL)
		for (i = 0; i < n; i++)
			dest[i] = src[i];
	return (dest);
}
