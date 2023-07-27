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
	int printed_chars = 0;
	char *str = va_arg(f->args, char *);

	if (str == NULL)
		str = "(null)";
	printed_chars += print_string_format(str, f, buf, ctr);
	return (printed_chars);
}
