#include "main.h"
#include <stdarg.h>

/**
 * handle_integer - handler function for signed integer conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_integer(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0, num = va_arg(args, int);
	char *int_str, int_buf[INT_BUF_SIZE] = "000000000000";

	int_str = convert_int_to_str(num, int_buf, INT_BUF_SIZE);
	if (f->plus_flag == 1 && num >= 0)
		printed_chars += _putchar_buf('+', buf, ctr);
	else if (f->blank_flag == 1 && num >= 0)
		printed_chars += _putchar_buf(' ', buf, ctr);
	printed_chars += _puts_buf(int_str, buf, ctr);
	return (printed_chars);
}
