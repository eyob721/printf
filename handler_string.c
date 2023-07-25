#include "main.h"
#include <stdarg.h>

/**
 * handle_string - handler function for string conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_string(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *str = va_arg(args, char *);

	(void)f;
	if (str == NULL)
		str = "(null)";
	printed_chars += _puts_buf(str, buf, ctr);
	return (printed_chars);
}
