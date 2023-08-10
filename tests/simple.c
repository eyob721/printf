#include "../printf.h"

/**
 * main - a simple printf test
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	_printf("A simple print\n");
	_printf("Print a character %c\n", 'A');
	return(0);
}
