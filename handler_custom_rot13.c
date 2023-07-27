#include "main.h"

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
				printed_chars += _putchar_buf(*o, buf, ctr);
				break;
			}
			++i, ++o;
		}
		if (*i == '\0')
			printed_chars += _putchar_buf(*str, buf, ctr);
		++str;
		i = input;
		o = output;
	}

	return (printed_chars);
}
