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
	int len, printed_chars = 0;
	char *chr_fmt, chr = va_arg(f->args, int);

	chr_fmt = format_character_output(&chr, &len, f);

	printed_chars += _puts_nbytes_buf(chr_fmt, len, buf, ctr);
	free(chr_fmt);
	return (printed_chars);
}
