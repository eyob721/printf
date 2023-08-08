#include "printf.h"
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
	sum = _printf("[10879156784]: %ld\n", 10879156784);
	printf("[Got]: %d\n", sum);
	sum = printf("[10879156784]: %ld\n", 10879156784);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[LONG_MAX]: %ld\n", LONG_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[LONG_MAX]: %ld\n", LONG_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[LONG_MIN]: %ld\n", LONG_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[LONG_MIN]: %ld\n", LONG_MIN);
	printf("[Exp]: %d\n", sum);
	_printf("--------------------------------------------------------------\n");

	_printf("--------------------------------------------------------------\n");
	_printf("                  UNSIGNED INTEGERS (u)                    \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[127248354879]: %lu\n", 127248354879);
	printf("[Got]: %d\n", sum);
	sum = printf("[127248354879]: %lu\n", 127248354879);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[ULONG_MAX]: %lu\n", ULONG_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[ULONG_MAX]: %lu\n", ULONG_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[1265465511651035]: %lu\n", 1265465511651035);
	printf("[Got]: %d\n", sum);
	sum = printf("[1265465511651035]: %lu\n", 1265465511651035);
	printf("[Exp]: %d\n", sum);

	_printf("--------------------------------------------------------------\n");

	_printf("--------------------------------------------------------------\n");
	_printf("                          OCTAL (o)                           \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[127248354879]: %lo\n", 127248354879);
	printf("[Got]: %d\n", sum);
	sum = printf("[127248354879]: %lo\n", 127248354879);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[ULONG_MAX]: %lo\n", ULONG_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[ULONG_MAX]: %lo\n", ULONG_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[1265465511651035]: %lo\n", 1265465511651035);
	printf("[Got]: %d\n", sum);
	sum = printf("[1265465511651035]: %lo\n", 1265465511651035);
	printf("[Exp]: %d\n", sum);

	_printf("--------------------------------------------------------------\n");

	_printf("--------------------------------------------------------------\n");
	_printf("                       HEXADECIMAL (x, X)                     \n");
	_printf("--------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[127248354879]: %lx\n", 127248354879);
	printf("[Got]: %d\n", sum);
	sum = printf("[127248354879]: %lx\n", 127248354879);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[ULONG_MAX]: %lx\n", ULONG_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[ULONG_MAX]: %lx\n", ULONG_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[1265465511651035]: %lx\n", 1265465511651035);
	printf("[Got]: %d\n", sum);
	sum = printf("[1265465511651035]: %lx\n", 1265465511651035);
	printf("[Exp]: %d\n", sum);

	_printf("--------------------------------------------------------------\n");

	return (0);
}
