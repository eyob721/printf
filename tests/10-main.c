#include "printf.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - test program for task 10
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	_printf("\n------------------------------------------------------------\n");
	_printf("            precision has no effect on CHAR                   \n");
	_printf("--------------------------------------------------------------\n");

	/* printf("\nTest-%i:\n-----------------------------------------------\n", i++); */
	/* sum = _printf("[%.7c]\n", 'A'); */
	/* printf("[Got]: %d\n", sum); */
	/* sum = printf("[%.7c]\n", 'A'); */
	/* printf("[Exp]: %d\n", sum); */

	/* printf("\nTest-%i:\n-----------------------------------------------\n", i++); */
	/* sum = _printf("[%7.10c]\n", 0); */
	/* printf("[Got]: %d\n", sum); */
	/* sum = printf("[%7.10c]\n", 0); */
	/* printf("[Exp]: %d\n", sum); */

	_printf("\n------------------------------------------------------------\n");
	_printf("                          STRING                              \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.7s]\n", "Alx");
	printf("[Got]: %d\n", sum);
	sum = printf("[%.7s]\n", "Alx");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.2s]\n", "Alx");
	printf("[Got]: %d\n", sum);
	sum = printf("[%.2s]\n", "Alx");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%5.2s]\n", "Alx");
	printf("[Got]: %d\n", sum);
	sum = printf("[%5.2s]\n", "Alx");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0s]\n", "Alx");
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0s]\n", "Alx");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%5.2s]\n", "Alx is awesome");
	printf("[Got]: %d\n", sum);
	sum = printf("[%5.2s]\n", "Alx is awesome");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.7s]\n", "Best School !\n");
	printf("[Got]: %d\n", sum);
	sum = printf("[%.7s]\n", "Best School !\n");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.*s]\n", 7, "Best School !\n");
	printf("[Got]: %d\n", sum);
	sum = printf("[%.*s]\n", 7, "Best School !\n");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.*s]\n", 7, "Hi!\n");
	printf("[Got]: %d\n", sum);
	sum = printf("[%.*s]\n", 7, "Hi!\n");
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                          INTEGER                             \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.10d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.10d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[% .7d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[% .7d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%07d]\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%07d]\n", -7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.7d]\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.7d]\n", -7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(0) + precision(2), number[7284]\n");
	sum = _printf("[%.2d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.2d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(7) + precision(10), number[7284]\n");
	sum = _printf("[%7.10d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.10d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(7) + precision(2), number[7284]\n");
	sum = _printf("[%7.2d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.2d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(20) + precision(10), number[7284]\n");
	sum = _printf("[%20.10d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%20.10d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(20) + precision(10), number[7284]\n");
	sum = _printf("[%-20.10d]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%-20.10d]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(20) + precision(10), number[-7284]\n");
	sum = _printf("[%20.10d]\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%20.10d]\n", -7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(20) + precision(10), number[-7284]\n");
	sum = _printf("[%-20.10d]\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%-20.10d]\n", -7284);
	printf("[Exp]: %d\n", sum);

	printf("\nZERO TESTS-----------------------------------------------------------\n");
	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(7) + precision(2), number[0]\n");
	sum = _printf("[%7.2d]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.2d]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(20) + precision(10), number[0]\n");
	sum = _printf("[%20.10d]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%20.10d]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(7) + precision(10), number[0]\n");
	sum = _printf("[%7.10d]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.10d]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(7) + precision(0), number[0]\n");
	sum = _printf("[%7.0d]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.0d]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	printf("width(0) + precision(0), number[0]\n");
	sum = _printf("[%.0d]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0d]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\n-----------------------------------------------------------\n");
	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.6d]\n", -1024);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.6d]\n", -1024);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%+.6d]\n", 1024);
	printf("[Got]: %d\n", sum);
	sum = printf("[%+.6d]\n", 1024);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0d]\n", 512);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0d]\n", 512);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                          UNSIGNED                            \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.10u]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.10u]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.2u]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.2u]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.10u]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.10u]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.2u]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.2u]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0u]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0u]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.u]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.u]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0u]\n", 512);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0u]\n", 512);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                            OCTAL                             \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.10o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.10o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.2o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.2o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.10o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.10o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.2o]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.2o]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0o]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0o]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.o]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.o]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0o]\n", 512);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0o]\n", 512);
	printf("[Exp]: %d\n", sum);

	_printf("\n------------------------------------------------------------\n");
	_printf("                        HEXADECIMAl                           \n");
	_printf("--------------------------------------------------------------\n");
	i = 0;

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.10x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.10x]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.2x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.2x]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.10x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.10x]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%7.2x]\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("[%7.2x]\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0x]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0x]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.x]\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.x]\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[%.0x]\n", 512);
	printf("[Got]: %d\n", sum);
	sum = printf("[%.0x]\n", 512);
	printf("[Exp]: %d\n", sum);


	return (0);
}
