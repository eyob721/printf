#include "main.h"

/**
 * handle_char - handler function for character conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_char(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char ch = va_arg(f->args, int);

	printed_chars += print_char_format(&ch, f, buf, ctr);
	return (printed_chars);
}
