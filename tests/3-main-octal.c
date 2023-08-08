#include "printf.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - test program for task 3 (octal)
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	_printf("------------------------------------------------------------\n");
	_printf("                        OCTAL                               \n");
	_printf("------------------------------------------------------------\n");

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[0]: %o\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[0]: %o\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[105]: %o\n", 105);
	printf("[Got]: %d\n", sum);
	sum = printf("[105]: %o\n", 105);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[-105]: %o\n", -105);
	printf("[Got]: %d\n", sum);
	sum = printf("[-105]: %o\n", -105);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[INT_MAX]: %o\n", INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[INT_MAX]: %o\n", INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n----------------------------------------\n", i++);
	sum = _printf("[UINT_MAX]: %o\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[UINT_MAX]: %o\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	return (0);
}
