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
	int printed_chars = 0;
	char *int_str, int_buf[INT_BUF_SIZE] = "000000000000";

	(void)f;
	int_str = convert_int_to_str(va_arg(args, int), int_buf, INT_BUF_SIZE);
	printed_chars += _puts_buf(int_str, buf, ctr);
	return (printed_chars);
}
