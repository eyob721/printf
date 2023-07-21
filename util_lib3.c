#include "main.h"

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

/**
 * _realloc - a function that reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: is the size in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 *
 * Return:
 *		- newly allocated memory if successful.
 *		- NULL, if ptr is NULL & new_size is 0, or if memory allocation fails.
 * Description:
 *		- newly allocated memory is initialized to prevent memory errors.
 *		- contents of the old memory (ptr) is copied to the new memory.
 *		- if ptr is NULL, and new_size is not 0, then the call is equivalent
 *		  to malloc(new_size).
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min_size;
	char *new_mem;

	/**
	 * if ptr is not NULL and new_size is 0, then
	 * the call is equivalent to free(ptr)
	 */
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* if old_size == new_size, then no new memory allocation is required */
	if (old_size == new_size)
		return (ptr);

	/* Allocate new memory */
	new_mem = malloc(new_size);
	if (new_mem == NULL)
		return (ptr);

	/* Initialize new memory */
	_memset(new_mem, 0, new_size);

	/* Copy contents of old memory to new memory and free old memory */
	if (ptr != NULL)
	{
		min_size = old_size < new_size ? old_size : new_size;
		for (i = 0; i < min_size; i++)
			new_mem[i] = *((char *)ptr + i);
		free(ptr);
	}

	return ((void *)new_mem);
}

/**
 * _strdup - a function that returns a pointer to a newly allocated space in
 *			 memory, which contains a copy of the string given as a parameter
 * @str: a given string
 *
 * Return: pointer to a newly allocated duplicate of the given string, or
 *		   NULL, if the given string is NULL, or if memory allocation failed
 */
char *_strdup(char *str)
{
	int i;
	char *dup;

	if (str == NULL)
		return (NULL);
	/* Find length for str, use i to store length */
	for (i = 0; str[i] != '\0'; i++)
		;
	dup = malloc(sizeof(char) * (i + 1)); /* +1 for '\0' character*/
	if (dup == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
