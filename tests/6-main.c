#include "main.h"
#include <stdio.h>

/**
 * main - test program for task 2
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[0]: %p\n", (void *)0);
	printf("[Got]: %d\n", sum);	
	sum = printf("[0]: %p\n", (void *)0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[105]: %p\n", (void *)105);
	printf("[Got]: %d\n", sum);
	sum = printf("[105]: %p\n", (void *)105);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[0x7ffe637541f0]: %p\n", (void *)0x7ffe637541f0);
	printf("[Got]: %d\n", sum);
	sum = _printf("[0x7ffe637541f0]: %p\n", (void *)0x7ffe637541f0);
	printf("[Exp]: %d\n", sum);

	return (0);
}
