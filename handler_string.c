#include "main.h"
#include <stdarg.h>

/**
 * handle_string - handler function for string conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_string(fmt_data_t *f, char *buf, int *ctr)
{
	int len, printed_chars = 0;
	char *str_fmt, *str = va_arg(f->args, char *);

	if (str == NULL)
		str = "(null)";

	str_fmt = format_character_output(str, &len, f);

	printed_chars += _puts_nbytes_buf(str_fmt, len, buf, ctr);
	free(str_fmt);
	return (printed_chars);
}
