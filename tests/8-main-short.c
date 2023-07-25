#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - test program for task 8 - short converison (h)
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	_printf("--------------------------------------------------------------\n");
	_printf("                    SIGNED INTEGERS (d, i)                    \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[12724]: %hd\n", 12724);
	printf("[Got]: %d\n", sum);
	sum = printf("[12724]: %hd\n", 12724);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[SHRT_MAX]: %hd\n", SHRT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[SHRT_MAX]: %hd\n", SHRT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[SHRT_MIN]: %hd\n", SHRT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[SHRT_MIN]: %hd\n", SHRT_MIN);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[42327]: %hd\n", 42327);
	printf("[Got]: %d\n", sum);
	sum = printf("[42327]: %hd\n", 42327);
	printf("[Exp]: %d\n", sum);
	_printf("--------------------------------------------------------------\n");

	_printf("--------------------------------------------------------------\n");
	_printf("                  UNSIGNED INTEGERS (u)                    \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[12724]: %hu\n", 12724);
	printf("[Got]: %d\n", sum);
	sum = printf("[12724]: %hu\n", 12724);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[USHRT_MAX]: %hu\n", USHRT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[USHRT_MAX]: %hu\n", USHRT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[420327]: %hu\n", 420327);
	printf("[Got]: %d\n", sum);
	sum = printf("[420327]: %hu\n", 420327);
	printf("[Exp]: %d\n", sum);

	_printf("--------------------------------------------------------------\n");

	_printf("--------------------------------------------------------------\n");
	_printf("                          OCTAL (o)                           \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[12724]: %ho\n", 12724);
	printf("[Got]: %d\n", sum);
	sum = printf("[12724]: %ho\n", 12724);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[USHRT_MAX]: %ho\n", USHRT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[USHRT_MAX]: %ho\n", USHRT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[420327]: %ho\n", 420327);
	printf("[Got]: %d\n", sum);
	sum = printf("[420327]: %ho\n", 420327);
	printf("[Exp]: %d\n", sum);

	_printf("--------------------------------------------------------------\n");

	_printf("--------------------------------------------------------------\n");
	_printf("                       HEXADECIMAL (x, X)                     \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[12724]: %hx\n", 12724);
	printf("[Got]: %d\n", sum);
	sum = printf("[12724]: %hx\n", 12724);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[USHRT_MAX]: %hx\n", USHRT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[USHRT_MAX]: %hx\n", USHRT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[420327]: %hx\n", 420327);
	printf("[Got]: %d\n", sum);
	sum = printf("[420327]: %hx\n", 420327);
	printf("[Exp]: %d\n", sum);

	_printf("--------------------------------------------------------------\n");

	return (0);
}
