#include "main.h"

/**
 * handle_unsigned - handler function for unsigned conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_unsigned(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	unsigned long int num;
	char *uint_str, uint_buf[UINT_BUF_SIZE] = "#####################";

	if (f->modifier == 'h')
		num = (unsigned short)va_arg(f->args, unsigned int);
	else if (f->modifier == 'l')
		num = va_arg(f->args, unsigned long int);
	else
		num = (unsigned int)va_arg(f->args, unsigned int);

	/* If both precision and num are zero, then you do nothing */
	if (f->precision == 0 && num == 0)
		return (0);

	uint_str = convert_uint_to_base_str(10, num, 'l', uint_buf, UINT_BUF_SIZE);

	printed_chars += print_integer_format(uint_str, f, buf, ctr);
	return (printed_chars);
}

