#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("->%s%c %d%%... %sPlease wait%c\n", "Loading", ':', 98, "", '\0');
	printf("[Got]: %d\n", len);
	len2 = printf("->%s%c %d%%... %sPlease wait%c\n", "Loading", ':', 98, "", '\0');
	printf("[Exp]: %d\n", len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ 1.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("->%s%c %i%%... %sPlease wait%c\n", "Loading", ':', 98, "", '\0');
	printf("[Got]: %d\n", len);
	len2 = printf("->%s%c %i%%... %sPlease wait%c\n", "Loading", ':', 98, "", '\0');
	printf("[Exp]: %d\n", len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ 2.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
