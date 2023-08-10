#include "../main.h"
#include <stdio.h>

/**
 * main - test program for task 0
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	int sum;
	int i = 0;

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("Hurray this works, 15 more tasks to go!!! \\o/ \n");
	printf("[Got]: %d\n", sum);
	sum = printf("Hurray this works, 15 more tasks to go!!! \\o/ \n");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("This is how we do it in %c%c%c\n", 'A', 'l', 'x');
	printf("[Got]: %d\n", sum);
	sum = printf("This is how we do it in %c%c%c\n", 'A', 'l', 'x');
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("My name is %s and I am from %s.\n", "Miki", "Bahir Dar");
	printf("[Got]: %d\n", sum);
	sum = printf("My name is %s and I am from %s.\n", "Miki", "Bahir Dar");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("%s%% have been loaded, please have patience\n", "70");
	printf("[Got]: %d\n", sum);
	sum = printf("%s%% have been loaded, please have patience\n", "70");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("[%s]\n", NULL);
	printf("[Got]: %d\n", sum);
	sum = printf("[%s]\n", NULL);
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("");
	printf("[Got]: %d\n", sum);
	sum = printf("");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("%");
	printf("[Got]: %d\n", sum);
	sum = printf("%");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf("% ");
	printf("[Got]: %d\n", sum);
	sum = printf("% ");
	printf("[Exp]: %d\n", sum);

	printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	sum = _printf(NULL);
	printf("[Got]: %d\n", sum);
	sum = printf(NULL);
	printf("[Exp]: %d\n", sum);

	return (0);
}
