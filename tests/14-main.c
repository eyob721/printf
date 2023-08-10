#include "../main.h"
#include <stdio.h>

/**
 * main - test for task 14
 *
 * Return: Always 0.
 */
int main(void)
{
    char s[] = "ROT13 (\"rotate by 13 places\", sometimes hyphenated ROT-13) is a simple letter substitution cipher.\n";
	int i = 0;

	_printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	_printf("[GOT]: %R\n", s);
	_printf("[EXP]: %s\n","EBG13 (\"ebgngr ol 13 cynprf\", fbzrgvzrf ulcurangrq EBG-13) vf n fvzcyr yrggre fhofgvghgvba pvcure." );

	_printf("\nTest-%d:\n-----------------------------------------------\n", i++);
	_printf("[GOT]: %R\n","EBG13 (\"ebgngr ol 13 cynprf\", fbzrgvzrf ulcurangrq EBG-13) vf n fvzcyr yrggre fhofgvghgvba pvcure." );
	_printf("[EXP]: %s\n", s);
    return (0);
}
