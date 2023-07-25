#include "main.h"

/**
 * handle_unsigned - handler function for unsigned conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_unsigned(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	unsigned long int num;
	char *uint_str, uint_buf[UINT_BUF_SIZE] = "#####################";

	if (f->modifier == 'h')
		num = (unsigned short)va_arg(args, unsigned int);
	else if (f->modifier == 'l')
		num = va_arg(args, unsigned long int);
	else
		num = (unsigned int)va_arg(args, unsigned int);

	uint_str = convert_uint_to_base_str(10, num, 'l', uint_buf, UINT_BUF_SIZE);
	printed_chars += _puts_buf(uint_str, buf, ctr);
	return (printed_chars);
}

