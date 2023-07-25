#include "main.h"

/* 33 = 32 (max no of digits) + 1 (for '\0') */
#define BIN_BUF_SIZE 33

/**
 * handle_binary - handler function for binary conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_binary(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *bin_str, bin_buf[BIN_BUF_SIZE] = "################################";

	(void)f;
	bin_str = convert_uint_to_base_str(2, va_arg(args, unsigned int), 'l',
									bin_buf, BIN_BUF_SIZE);
	while (*bin_str != '\0')
		printed_chars += _putchar_buf(*(bin_str++), buf, ctr);
	return (printed_chars);
}
