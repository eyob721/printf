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
	char *hex_str, hex_buf[HEX_BUF_SIZE] = "###################", ltr = 'l';

	if (f->modifier == 'h')
		num = (unsigned short)va_arg(f->args, unsigned int);
	else if (f->modifier == 'l')
		num = va_arg(f->args, unsigned long int);
	else
		num = (unsigned int)va_arg(f->args, unsigned int);

	/* If both precision and num are zero, then you do nothing */
	if (f->precision == 0 && num == 0)
		return (0);

	if (f->spc_chr == 'X')
		ltr = 'C';

	hex_str = convert_uint_to_base_str(16, num, ltr, hex_buf, HEX_BUF_SIZE);
	if (f->hash_flag == 1 && num != 0)
	{
		if (f->spc_chr == 'x')
			*(--hex_str) = 'x';
		else
			*(--hex_str) = 'X';
		*(--hex_str) = '0';
	}

	printed_chars += print_integer_format(hex_str, f, buf, ctr);
	return (printed_chars);
}
