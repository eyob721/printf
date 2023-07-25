#include "main.h"
#include <stdio.h>

/**
 * main - test program for task 5
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("%S\n", "Best\nSchool");
	printf("[Got]: %d\n", sum);

	return (0);
}
