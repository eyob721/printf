#include "main.h"

/**
 * handle_char - handler function for character conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_char(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char ch = va_arg(args, int);

	(void)f;
	if (f->width > 1)
	{
		printed_chars += _print_fmt_str_buf(&ch, f, buf, ctr);
		return (printed_chars);
	}
	printed_chars += _putchar_buf(ch, buf, ctr);
	return (printed_chars);
}
