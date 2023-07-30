#include "main.h"

/**
 * handle_hexadecimal- handler function for hexadecimal conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_hexadecimal(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	unsigned long int num;
	char *hex_fmt, prefix[3] = "0x", ltr = f->spc_chr == 'x' ? 'x' : 'X';
	char *hex_str, hex_buf[HEX_BUF_SIZE] = "###################";

	if (f->modifier == 'h')
		num = (unsigned short)va_arg(f->args, unsigned int);
	else if (f->modifier == 'l')
		num = va_arg(f->args, unsigned long int);
	else
		num = (unsigned int)va_arg(f->args, unsigned int);

	if (f->spc_chr == 'X' && f->hash_flag == 1)
		prefix[1] = 'X';
	else if (f->hash_flag == 0 || num == 0)
		prefix[0] = '\0';

	/* If both precision and num are zero, then you do nothing */
	if (f->precision == 0 && num == 0)
		return (0);

	hex_str = convert_uint_to_base_str(16, num, ltr, hex_buf, HEX_BUF_SIZE);

	hex_fmt = format_integer_output(hex_str, prefix, f);

	printed_chars += _puts_buf(hex_fmt, buf, ctr);
	free(hex_fmt);
	return (printed_chars);
}
