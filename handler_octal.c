#include "main.h"

/**
 * handle_octal - handler function for octal conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_octal(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *oct_str, oct_buf[OCT_BUF_SIZE] = "############";

	(void)f;
	oct_str = convert_uint_to_base_str(8, va_arg(args, unsigned int), 'l',
									oct_buf, OCT_BUF_SIZE);
	printed_chars += _puts_buf(oct_str, buf, ctr);
	return (printed_chars);
}
