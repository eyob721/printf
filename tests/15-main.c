#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - test program for task 11
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	_printf("\n------------------------------------------------------------\n");
	_printf("                              CHAR                            \n");
	_printf("--------------------------------------------------------------\n");

	_printf("\n------------------------------------------------------------\n");
	_printf("                             STRING                           \n");
	_printf("--------------------------------------------------------------\n");

	_printf("\n------------------------------------------------------------\n");
	_printf("                          INTEGER                             \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;
	_printf("\n-------------\n");
	_printf("Test case 1\n");
	_printf("-------------\n");
	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%+07d]\n", INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%+07d]\n", INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%+07d]\n", INT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[%+07d]\n", INT_MIN);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%+07d]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%+07d]\n", 0);
	printf("[Exp]: %d\n", sum);

	_printf("\n-------------\n");
	_printf("Test case 2\n");
	_printf("-------------\n");
	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.*d]\n", 0, INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.*d]\n", 0, INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.*d]\n", 0, INT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.*d]\n", 0, INT_MIN);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.*d]\n", 0, 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.*d]\n", 0, 0);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                          UNSIGNED                            \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	_printf("\n------------------------------------------------------------\n");
	_printf("                            OCTAL                             \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	_printf("\n------------------------------------------------------------\n");
	_printf("                        HEXADECIMAl                           \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	return (0);
}
