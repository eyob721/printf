#include "printf.h"
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
	_printf("            zero flag has no effect on CHAR                   \n");
	_printf("--------------------------------------------------------------\n");

	_printf("\n------------------------------------------------------------\n");
	_printf("            zero flag has no effect on STRING                 \n");
	_printf("--------------------------------------------------------------\n");

	_printf("\n------------------------------------------------------------\n");
	_printf("                          INTEGER                             \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("zero only \n");
	sum = _printf("[%0d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%0d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero\n");
	sum = _printf("[%07d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%07d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero + space (+ve number)\n");
	sum = _printf("[% 07d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[% 07d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero (-ve number)\n");
	sum = _printf("[%07d]\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%07d]\n", -7284);
	printf("[Exp]: %d\n", sum);

	_printf("zero and minus = don't work (zero is ignored)\n");
	_printf("zero and precision = don't work (zero is ignored)\n");

	_printf("\n------------------------------------------------------------\n");
	_printf("                          UNSIGNED                            \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%0u]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%0u]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%07u]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%07u]\n", 7284);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                            OCTAL                             \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("zero\n");
	sum = _printf("[%0o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%0o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero\n");
	sum = _printf("[%07o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%07o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero + hash\n");
	sum = _printf("[%0#7o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%0#7o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                        HEXADECIMAl                           \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("zero\n");
	sum = _printf("[%0x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%0x]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero\n");
	sum = _printf("[%07x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%07x]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	_printf("width + zero + hash\n");
	sum = _printf("[%0#7x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%0#7x]\n", 7284);
	printf("[Exp]: %d\n", sum);


	return (0);
}
