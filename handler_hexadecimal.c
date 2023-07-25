#include "main.h"

/**
 * handle_hexadecimal- handler function for hexadecimal conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_hexadecimal(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *hex_str, hex_buf[HEX_BUF_SIZE] = "#########";

	(void)f;
	if (f->spc_chr == 'x')
		hex_str = convert_uint_to_base_str(16, va_arg(args, unsigned int),
											'l', hex_buf, HEX_BUF_SIZE);
	else
		hex_str = convert_uint_to_base_str(16, va_arg(args, unsigned int),
											'C', hex_buf, HEX_BUF_SIZE);
	printed_chars += _puts_buf(hex_str, buf, ctr);
	return (printed_chars);
}
