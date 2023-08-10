#include "../main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - test program for task 1
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	printf("----------------------------------------------------------------\n");
	printf("d - conversion\n");
	printf("----------------------------------------------------------------\n");

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("%d\n", 0);
	printf("[Got]: %d\n", sum);
	sum = printf("%d\n", 0);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("%d\n", 7284);
	printf("[Got]: %d\n", sum);
	sum = printf("%d\n", 7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("%d\n", -7284);
	printf("[Got]: %d\n", sum);
	sum = printf("%d\n", -7284);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[INT_MAX]: %d\n", INT_MAX);
	printf("[Got]: %d\n", sum);
	sum = printf("[INT_MAX]: %d\n", INT_MAX);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[INT_MIN]: %d\n", INT_MIN);
	printf("[Got]: %d\n", sum);
	sum = printf("[INT_MIN]: %d\n", INT_MIN);
	printf("[Exp]: %d\n", sum);

	i = 0;
	printf("----------------------------------------------------------------\n");
	printf("i - conversion\n");
	printf("----------------------------------------------------------------\n");

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("%i\n", 0);
	printf("[Got]: %i\n", sum);
	sum = printf("%i\n", 0);
	printf("[Exp]: %i\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("%i\n", 7284);
	printf("[Got]: %i\n", sum);
	sum = printf("%i\n", 7284);
	printf("[Exp]: %i\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("%i\n", -7284);
	printf("[Got]: %i\n", sum);
	sum = printf("%i\n", -7284);
	printf("[Exp]: %i\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[INT_MAX]: %i\n", INT_MAX);
	printf("[Got]: %i\n", sum);
	sum = printf("[INT_MAX]: %i\n", INT_MAX);
	printf("[Exp]: %i\n", sum);

	printf("\nTest-%i:\n-----------------------------------------------\n", i++);
	sum = _printf("[INT_MIN]: %i\n", INT_MIN);
	printf("[Got]: %i\n", sum);
	sum = printf("[INT_MIN]: %i\n", INT_MIN);
	printf("[Exp]: %i\n", sum);
	return (0);
}
