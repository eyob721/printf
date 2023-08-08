#include "printf.h"
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

	_printf("\n------------------------------------------------------------\n");
	_printf("                            CHAR                              \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7c]\n", 'A');
	printf("[Got]: %d\n", sum);
	sum = printf("[%7c]\n", 'A');
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7c]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7c]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%*c]\n", 20, 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%*c]\n", 20, 0);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                          STRING                              \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%20s]\n", "Alx");
	printf("[Got]: %d\n", sum);
	sum = printf("[%20s]\n", "Alx");
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                          INTEGER                             \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%50d]\n", INT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[%50d]\n", INT_MIN);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + plus (+ve number)\n");
	sum = _printf("[%+50d]\n", INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%+50d]\n", INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero (-ve number)\n");
	sum = _printf("[%049d]\n", INT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[%049d]\n", INT_MIN);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                          UNSIGNED                            \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%50u]\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%50u]\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                            OCTAL                             \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%#50o]\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%#50o]\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                        HEXADECIMAl                           \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%#50x]\n", UINT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%#50x]\n", UINT_MAX);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                         POINTER                              \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7p]\n", (void *)0x7faf51f0f608);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7p]\n", (void *)0x7faf51f0f608);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%21p]\n", (void *)0x7faf51f0f608);
	printf("[Got]: %d\n", sum);
	sum = printf("[%21p]\n", (void *)0x7faf51f0f608);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%21p]\n", NULL);
	printf("[Got]: %d\n", sum);
	sum = printf("[%21p]\n", NULL);
	printf("[Exp]: %d\n", sum);
	return (0);
}
