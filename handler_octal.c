#include "main.h"

/**
 * handle_octal - handler function for octal conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_octal(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	unsigned long int num;
	char *oct_fmt, prefix[2] = {0};
	char *oct_str, oct_buf[OCT_BUF_SIZE] = "########################";

	if (f->modifier == 'h')
		num = (unsigned short)va_arg(f->args, unsigned int);
	else if (f->modifier == 'l')
		num = va_arg(f->args, unsigned long int);
	else
		num = (unsigned int)va_arg(f->args, unsigned int);

	if (f->hash_flag == 1 && num != 0)
		*prefix = '0';

	/* If both precision and num are zero, then you do nothing */
	if (f->precision == 0 && num == 0)
		oct_str = "";
	else
		oct_str = convert_uint_to_base_str(8, num, 'l', oct_buf, OCT_BUF_SIZE);

	oct_fmt = format_integer(oct_str, prefix, f);

	printed_chars += _puts_buf(oct_fmt, buf, ctr);
	free(oct_fmt);
	return (printed_chars);
}
