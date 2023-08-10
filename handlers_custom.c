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
		printed_chars += _putchar_buf(f->fd, *(bin_str++), buf, ctr);
	return (printed_chars);
}

/**
 * handle_custom_string - handler function for custom string conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127) are
 *				printed this way: \x, followed by the ASCII code value in
 *				hexadecimal (upper case - always 2 characters)
 */
int handle_custom_string(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char ch, *str, *hex_str, hex_buf[HEX_BUF_SIZE] = "#################";

	str = va_arg(f->args, char *);
	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		ch = *str;
		if ((ch > 0 && ch < 32) || ch >= 127)
		{
			printed_chars += _puts_buf(f->fd, "\\x", buf, ctr);
			hex_str = convert_uint_to_base_str(16, ch, 'C', hex_buf, HEX_BUF_SIZE);
			if (_strlen(hex_str) == 1)
				printed_chars += _putchar_buf(f->fd, '0', buf, ctr);
			printed_chars += _puts_buf(f->fd, hex_str, buf, ctr);
			str++;
			continue;
		}
		printed_chars += _putchar_buf(f->fd, ch, buf, ctr);
		str++;
	}
	return (printed_chars);
}

/**
 * handle_custom_rot13 - handler function for custom rot13 string conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_custom_rot13(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str, *i = input, *o = output;

	str = va_arg(f->args, char *);
	if (str == NULL)
		str = "(null)";


	while (*str != '\0')
	{
		while (*i != '\0')
		{
			if (*str == *i)
			{
				printed_chars += _putchar_buf(f->fd, *o, buf, ctr);
				break;
			}
			++i, ++o;
		}
		if (*i == '\0')
			printed_chars += _putchar_buf(f->fd, *str, buf, ctr);
		++str;
		i = input;
		o = output;
	}

	return (printed_chars);
}

/**
 * handle_custom_reverse_string - handler function for custom reverse string
 *								  conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_custom_reverse_string(fmt_data_t *f, char *buf, int *ctr)
{
	int i, printed_chars = 0;
	char *str;

	str = va_arg(f->args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = _strlen(str) - 1; i >= 0; --i)
		printed_chars += _putchar_buf(f->fd, str[i], buf, ctr);
	return (printed_chars);
}
