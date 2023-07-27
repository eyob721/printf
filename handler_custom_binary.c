#include "main.h"

/**
 * handle_custom_binary - handler function for custom binary conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_custom_binary(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *bin_str, bin_buf[BIN_BUF_SIZE] = "################################";

	bin_str = convert_uint_to_base_str(2, va_arg(f->args, unsigned int), 'l',
									bin_buf, BIN_BUF_SIZE);
	while (*bin_str != '\0')
		printed_chars += _putchar_buf(*(bin_str++), buf, ctr);
	return (printed_chars);
}
