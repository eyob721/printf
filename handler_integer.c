#include "main.h"
#include <stdarg.h>

/**
 * handle_integer - handler function for signed integer conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_integer(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	long int num;
	char *int_fmt, prefix[2] = {0};
	char *int_str, int_buf[INT_BUF_SIZE] = "####################";

	if (f->modifier == 'h')
		num = (short)va_arg(f->args, int);
	else if (f->modifier == 'l')
		num = va_arg(f->args, long int);
	else
		num = (int)va_arg(f->args, int);

	if (num < 0)
		*prefix = '-';
	else if (f->plus_flag == 1 && num >= 0)
		*prefix = '+';
	else if (f->blank_flag == 1 && num >= 0)
		*prefix = ' ';

	/* If both precision and num are zero, then no need for formatting */
	if (f->precision == 0 && num == 0)
		int_str = "";
	else
		int_str = convert_int_to_str(num, int_buf, INT_BUF_SIZE);

	int_fmt = format_integer_output(int_str, prefix, f);

	printed_chars += _puts_buf(int_fmt, buf, ctr);

	free(int_fmt);
	return (printed_chars);
}
