#include "main.h"

/**
 * _printf - implementation of printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	char *ptr = (char *)format;
	int printed_chars = 0, fmt_case = 0;
	va_list args;

	(void)args;
	if (format == NULL)
		return (0);
	while (*ptr != '\0')
	{
		switch (fmt_case)
		{
		case 0: /* NORMAL */
			if (*ptr == '%')
			{
				fmt_case = 1;
				break;
			}
			printed_chars += _putchar(*ptr);
			++ptr;
		break;
		case 1:  /* CONVERSION */
		break;
		}
	}
	return (printed_chars);
}
