#include "../main.h"

/**
 * main - a simple printf test
 *
 * Return: 0 on success, or 1 on error
 */
int main(void)
{
	_printf("A simple print\n");
	_printf("Print a character %c\n", 'A');
	_printf("Print a string [%s]\n", "Alx is awesome");
	return(0);
}
