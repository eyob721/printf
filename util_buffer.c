#include "main.h"

/**
 * _putchar_buf - a function that writes a character to the format buffer
 * @c: a character
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 * Description: when a buffer flush signal is sent, or when the counter of the
 *				format buffer reaches the last index (i.e. BUFFER_SIZE - 1, or
 *				1024 - 1) it will write the contents of the buffer to stdout and
 *				resets the counter to 0
 */
int _putchar_buf(char c, char *buf, int *ctr)
{
	int printed_chars = 0;

	if (c == BUFFER_FLUSH || *ctr == BUFFER_SIZE - 2)
	{
		printed_chars += write(STDOUT_FILENO, buf, *ctr);
		*ctr = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[(*ctr)++] = c;
	return (printed_chars);
}

/**
 * _puts_buf - a function that writes a string to the format buffer
 * @str: a string
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 */
int _puts_buf(char *str, char *buf, int *ctr)
{
	int printed_chars = 0;

	while (str != NULL && *str != '\0')
		printed_chars += _putchar_buf(*(str++), buf, ctr);
	return (printed_chars);
}

/**
 * _print_fmt_str_buf - a function that formattes a string and writes it to the
 *						format buffer
 * @str: a string to be formatted
 * @f: pointer to the format options
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 */
int _print_fmt_str_buf(char *str, fmt_opts_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *fmt_str;

	fmt_str = malloc(sizeof(char) * (f->width + 1)); /* +1 for '\0' */
	if (fmt_str == NULL)
		return (0);

	_memset(fmt_str, ' ', f->width);

	write_str_justify_right(fmt_str, str, f->width + 1);

	printed_chars += _puts_buf(fmt_str, buf, ctr);

	free(fmt_str);

	return (printed_chars);
}

/**
 * write_str_justify_right - a function writes a string on the allocated format
 *							 string from the right
 * @fmt_str: format string
 * @str: string to written on format string
 * @size: size of the format string
 *
 * Return: void
 */
void write_str_justify_right(char *fmt_str, char *str, int size)
{
	int len = _strlen(str);

	while (len >= 0 && size >= 0)
	{
		fmt_str[size - 1] = str[len];
		--len;
		--size;
	}
}
