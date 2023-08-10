#include "../main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - test program for task 3
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	_printf("------------------------------------------------------------\n");
	_printf("                        UNSIGNED                            \n");
	_printf("------------------------------------------------------------\n");

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[0]: %u\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[0]: %u\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[105]: %u\n", 105);
	printf("[Got]: %d\n", sum);
	sum = printf("[105]: %u\n", 105);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[-105]: %u\n", -105);
	printf("[Got]: %d\n", sum);
	sum = printf("[-105]: %u\n", -105);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[INT_MAX]: %u\n", INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[INT_MAX]: %u\n", INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[UINT_MAX]: %u\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[UINT_MAX]: %u\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	return (0);
}
