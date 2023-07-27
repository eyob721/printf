#include "main.h"

/**
 * print_char_format - a function that formattes a string and writes it to the
 *						format buffer
 * @str: a string to be formatted
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 */
int print_char_format(char *str, fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *fmt_str;

	/* Check if formatting is needed */
	if (f->width < 1)
	{
		printed_chars += _putchar_buf(*str, buf, ctr);
		return (printed_chars);
	}

	/* Format output */
	fmt_str = malloc(sizeof(char) * (f->width + 1)); /* +1 for '\0' */
	if (fmt_str == NULL)
		return (0);

	fmt_str[f->width] = '\0';
	_memset(fmt_str, ' ', f->width);

	if (f->minus_flag == 1)
		write_format_justify_left(fmt_str, f->width, str, _strlen(str));
	else
		write_format_justify_right(fmt_str, f->width, str, _strlen(str));

	printed_chars += _puts_nbytes_buf(fmt_str, f->width, buf, ctr);
	free(fmt_str);
	return (printed_chars);
}

/**
 * print_string_format - a function that formats a string and writes it to the
 *						 format buffer
 * @str: a string to be formatted
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 * Description:
 *			- precision determines maximum number of characters to print
 *			  if the precision is less than the length of the string,
 *			  then the string is truncated
 *			- width determines width of the area to print on
 *			  if the width is less than the length of the string then it
 *			  is ignored, meaning you wont have to set it up
 */
int print_string_format(char *str, fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0, max_len = _strlen(str);
	char *fmt_str;

	/* Truncate 'str' if precision is set and is less than the length of 'str'*/
	if (f->precision >= 0 && f->precision < max_len)
		max_len = f->precision;

	/* Check if formatting is needed */
	if (f->width < max_len)
	{
		printed_chars += _puts_nbytes_buf(str, max_len, buf, ctr);
		return (printed_chars);
	}

	/* Format output */
	fmt_str = malloc(sizeof(char) * (f->width + 1)); /* +1 for '\0' */
	if (fmt_str == NULL)
		return (0);
	fmt_str[f->width] = '\0';
	_memset(fmt_str, ' ', f->width);

	if (f->minus_flag == 1)
		write_format_justify_left(fmt_str, f->width, str, max_len);
	else
		write_format_justify_right(fmt_str, f->width, str, max_len);

	printed_chars += _puts_nbytes_buf(fmt_str, f->width, buf, ctr);
	free(fmt_str);
	return (printed_chars);
}

/**
 * print_integer_format - a function that formats an integer and writes it to
 *						  the format buffer
 * @int_str: an integer string to be formatted
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 * Description:
 *		- First we check if formatting is needed, by checking if the number of
 *		  digits (len) is less than the format size (precision or the width)
 *		- size of the format width is MAX(width, precision)
 *		- if the maximum is precision or if zero flag is set, padding is '0',
 *		  otherwise it is ' ' by default
 *		- if the padding is '0' and the integer has a sign, it must be
 *		  written at the front and the format size also increments by 1
 *		- the sign and padding is handled by switching the sign character of the
 *		  integer string and and the first character in the format string, but
 *		  only in the case that the padding is '0'
 */
int print_integer_format(char *int_str, fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0, len = _strlen(int_str);
	int fmt_size = MAX(f->width, f->precision);
	char pad = ' ', sign;
	char *fmt_str;

	/* Check if formatting is needed */
	if (fmt_size < len)
	{
		printed_chars += _puts_buf(int_str, buf, ctr);
		return (printed_chars);
	}
	/* Format output */
	if (fmt_size == f->precision || f->zero_flag == 1)
		pad = '0';
	sign = pad;
	if (pad == '0' && (*int_str == '+' || *int_str == ' ' || *int_str == '-'))
	{
		sign = *int_str;
		*int_str = pad;
		++fmt_size; /* To accommodate the sign */
	}
	fmt_str = malloc(sizeof(char) * (fmt_size + 1)); /* +1 for '\0' */
	if (fmt_str == NULL)
		return (0);
	fmt_str[fmt_size] = '\0';
	_memset(fmt_str, pad, fmt_size);
	if (f->minus_flag == 1)
		write_format_justify_left(fmt_str, fmt_size, int_str, len);
	else
		write_format_justify_right(fmt_str, fmt_size, int_str, len);
	if (pad == '0')
		*fmt_str = sign;
	printed_chars += _puts_nbytes_buf(fmt_str, fmt_size, buf, ctr);
	free(fmt_str);
	return (printed_chars);
}

/**
 * write_format_justify_right - a function writes a string on the allocated
 *								format string, justified to the right
 * @fmt_str: format string
 * @str: string to written on format string
 * @size: size of the format string
 * @len: length of the string to be written 'str'
 *
 * Return: void
 * Description: In case of an empty string, it also must be printed on the
 *				format string.
 */
void write_format_justify_right(char *fmt_str, int size, char *str, int len)
{
	/* If 'str' is an empty string, write it on 'fmt_str' */
	if (*str == '\0')
	{
		fmt_str[size - 1] = *str;
		return;
	}

	/* If 'str' is not empty, write it from right to left on 'fmt_str' */
	for (--len; len >= 0 && size >= 0; --len, --size)
		fmt_str[size - 1] = str[len];
}

/**
 * write_format_justify_left - a function writes a string on the allocated
 *							   format string, justified to the left
 * @fmt_str: format string
 * @str: string to written on format string
 * @size: size of the format string
 * @len: length of the string to be written 'str'
 *
 * Return: void
 * Description: In case of an empty string, it also must be printed on the
 *				format string.
 */
void write_format_justify_left(char *fmt_str, int size, char *str, int len)
{
	/* If 'str' is an empty string, write it on 'fmt_str' */
	if (*str == '\0')
	{
		fmt_str[size - 1] = *str;
		return;
	}

	/* If 'str' is not empty, write it from left to right on 'fmt_str' */
	for (--len; len >= 0 && size >= 0; --len, --size)
		*(fmt_str++) = *(str++);
}
