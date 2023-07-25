#include "main.h"
#include <stdarg.h>

/**
 * handle_percent - handler function for percent conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_percent(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;

	(void)f;
	(void)args;
	printed_chars += _putchar_buf('%', buf, ctr);
	return (printed_chars);
}
