#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - test program for task 9
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%20s]\n", "Alx");
	printf("[Got]: %d\n", sum);
	sum = printf("[%20s]\n", "Alx");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%20c]\n", 'A');
	printf("[Got]: %d\n", sum);
	sum = printf("[%20c]\n", 'A');
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%50d]\n", INT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[%50d]\n", INT_MIN);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%+50d]\n", INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%+50d]\n", INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%50u]\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%50u]\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%#50o]\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%#50o]\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%#50x]\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%#50x]\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	return (0);
}
