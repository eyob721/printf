#include "main.h"
#include <stdio.h>

/**
 * main - test program for task 0
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;

	sum = _printf("Hurray this works, 15 task more to go!\n");
	printf("[Got]: %d\n", sum);
	sum = printf("Hurray this works, 15 task more to go!\n");
	printf("[Exp]: %d\n", sum);

	return (0);
}
