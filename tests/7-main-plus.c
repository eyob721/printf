#include "../main.h"
#include <stdio.h>

/**
 * main -  a test program for task 7 ('+' flag)
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum = 0, i = 0;

	(void)sum;
	(void)i;
	_printf("\n------------------------------------------------------------\n");
	_printf("				no effect on CHAR and STRING                   \n");
	_printf("--------------------------------------------------------------\n");

	_printf("\n------------------------------------------------------------\n");
	_printf("				        SIGNED INTEGER                         \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[0]: %+d\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[0]: %+d\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[7284]: %+d\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[7284]: %+d\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[-7284]: %+d\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[-7284]: %+d\n", -7284);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("	      no effect on UNSIGNED, OCTAL, and HEX                \n");
	_printf("--------------------------------------------------------------\n");

	return (0);
}
