#include "main.h"

/**
 * handle_custom_string - handler function for custom string conversion
 * @args: list of optional arguments given
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127) are
 *				printed this way: \x, followed by the ASCII code value in
 *				hexadecimal (upper case - always 2 characters)
 */
int handle_custom_string(va_list args, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char ch, *str, *hex_str, hex_buf[HEX_BUF_SIZE] = "#################";

	(void)f;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		ch = *str;
		if ((ch > 0 && ch < 32) || ch >= 127)
		{
			printed_chars += _puts_buf("\\x", buf, ctr);
			hex_str = convert_uint_to_base_str(16, ch, 'C', hex_buf, HEX_BUF_SIZE);
			if (_strlen(hex_str) == 1)
				printed_chars += _putchar_buf('0', buf, ctr);
			printed_chars += _puts_buf(hex_str, buf, ctr);
			str++;
			continue;
		}
		printed_chars += _putchar_buf(ch, buf, ctr);
		str++;
	}
	return (printed_chars);
}
