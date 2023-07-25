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
	unsigned int num = va_arg(args, unsigned int);
	char *hex_str, hex_buf[HEX_BUF_SIZE] = "#########";

	if (f->hash_flag == 1 && num != 0)
		printed_chars += _puts_buf("0x", buf, ctr);
	if (f->spc_chr == 'x')
		hex_str = convert_uint_to_base_str(16, num, 'l',
											hex_buf, HEX_BUF_SIZE);
	else
		hex_str = convert_uint_to_base_str(16, num, 'C',
											hex_buf, HEX_BUF_SIZE);
	printed_chars += _puts_buf(hex_str, buf, ctr);
	return (printed_chars);
}
