#include "printf.h"
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
	sum = _printf("[0]: %b\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[0]: %b\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[105]: %b\n", 105);
	printf("[Got]: %d\n", sum);
	sum = printf("[105]: %b\n", 105);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[7284]: %b\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[7284]: %b\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[-105]: %b\n", -105);
	printf("[Got]: %d\n", sum);
	sum = printf("[-105]: %b\n", -105);
	printf("[Exp]: %d\n", sum);

	return (0);
}
