#include "main.h"

/**
 * handle_custom_reverse_string - handler function for custom reverse string
 *								  conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_custom_reverse_string(fmt_data_t *f, char *buf, int *ctr)
{
	int i, printed_chars = 0;
	char *str;

	str = va_arg(f->args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = _strlen(str) - 1; i >= 0; --i)
		printed_chars += _putchar_buf(str[i], buf, ctr);
	return (printed_chars);
}
