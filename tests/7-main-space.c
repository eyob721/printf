#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main -  a test program for task 7 (' ' flag)
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum = 0, i = 0;
	long int l = INT_MAX;

	(void)sum;
	(void)i;
	_printf("----------------------------------------------------------------\n");
	_printf("				    space only  								 \n");
	_printf("----------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[0]: % d\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[0]: % d\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[7284]: % d\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[7284]: % d\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[-7284]: % d\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[-7284]: % d\n", -7284);
	printf("[Exp]: %d\n", sum);

	l += 1024;
	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[l]: % d\n", l);
	printf("[Got]: %d\n", sum);
	sum = printf("[l]: % d\n", l);
	printf("[Exp]: %d\n", sum);

	_printf("----------------------------------------------------------------\n");
	_printf("				    space and plus 								 \n");
	_printf("----------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[0]: % +d\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[0]: % +d\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[7284]: % +d\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[7284]: % +d\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[-7284]: % +d\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[-7284]: % +d\n", -7284);
	printf("[Exp]: %d\n", sum);
	return (0);
}
