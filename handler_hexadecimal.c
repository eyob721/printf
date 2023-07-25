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
	unsigned long int num;
	char *hex_str, hex_buf[HEX_BUF_SIZE] = "#################", ltr = 'l';

	if (f->modifier == 'h')
		num = (unsigned short)va_arg(args, unsigned int);
	else if (f->modifier == 'l')
		num = va_arg(args, unsigned long int);
	else
		num = (unsigned int)va_arg(args, unsigned int);

	if (f->hash_flag == 1 && num != 0)
		printed_chars += _puts_buf("0x", buf, ctr);

	if (f->spc_chr == 'X')
		ltr = 'C';

	hex_str = convert_uint_to_base_str(16, num, ltr, hex_buf, HEX_BUF_SIZE);

	printed_chars += _puts_buf(hex_str, buf, ctr);

	return (printed_chars);
}
