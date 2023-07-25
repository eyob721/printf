#include "main.h"

/**
 * _printf - implementation of printf function
 * @format: format string
 *
 * Return:
 *		- number of characters printed, or
 *		- -1 if there is an output error
 * Description:
 *		- Assume format syntax will be valid going in
 *		- If format syntax is invalid, then it goes into NORMAL state and
 *		  prints the characters as-is
 */
int _printf(const char *format, ...)
{
	char *ptr = (char *)format, *spc, fmt_buf[BUFFER_SIZE] = {0};
	int printed_chars = 0, fmt_case = 0, buf_ctr = 0, is_valid_syntax = 1;
	va_list args;
	fmt_opts_t fopts;
	int (*handle)(va_list, fmt_opts_t *, char *, int *);

	if (format == NULL || _strcmp((char *)format, "%") == 0 ||
			_strcmp((char *)format, "% ") == 0)
		return (-1);
	va_start(args, format);
	while (*ptr != '\0')
		switch (fmt_case)
		{
		case NORMAL:
			if (*ptr == '%' && is_valid_syntax)
			{
				fmt_case = CONVERSION;
				break;
			}
			printed_chars += _putchar_buf(*ptr, fmt_buf, &buf_ctr);
			++ptr, is_valid_syntax = 1;
		break;
		case CONVERSION:
			spc = get_specifier(ptr + 1, &fopts);
			if (spc != NULL) /* Valid format syntax */
			{
				handle = get_specifier_handler(*spc);
				printed_chars += handle(args, &fopts, fmt_buf, &buf_ctr);
				reset_format_options(&fopts);
				ptr = spc + 1;
			}
			else /* Invalid format syntax */
				is_valid_syntax = 0;
			fmt_case = NORMAL;
		break;
		}
	printed_chars += _putchar_buf(BUFFER_FLUSH, fmt_buf, &buf_ctr);
	va_end(args);
	return (printed_chars);
}
/**
 * get_specifier - a function that gets the specifier position while also
 *				   checking that format options set in the format string are set
 *				   in the correct format syntax.
 * @s: pointer to the position in the format string, next to the '%' character
 * @f: pointer to the format options
 *
 * Return: NULL if the format syntax is invalid, or a pointer to the conversion
 *		   specifier position in the format string
 * Description: The correct format syntax is as follows:
 *				%[flags][width][.precision][modifier]specifier
 *				NOTE: all other options are optional, except the specifier
 */
char *get_specifier(char *s, fmt_opts_t *f)
{
	if (*s == '\0')
		return (NULL);
	check_flag(&s, f);
	check_width(&s, f);
	check_precision(&s, f);
	check_modifier(&s, f);
	check_specifier(&s, f);
	return (s);
}

/**
 * get_specifier_handler - a function that fetches the right conversion
 *						   specifier handler function
 * @chr: the conversion specifier character
 *
 * Return: pointer to the respective conversion specifier handler function, or
 *		   NULL if the specifier is not supported
 */
int (*get_specifier_handler(char chr))(va_list, fmt_opts_t *, char *, int *)
{
	fmt_hndlr_t fmt_hndlr[] = {
		{'%', handle_percent},
		{'c', handle_char},
		{'s', handle_string},
		{'d', handle_integer},
		{'i', handle_integer},
		{'b', handle_binary},
		{'u', handle_unsigned},
		{'o', handle_octal},
		{'x', handle_hexadecimal},
		{'X', handle_hexadecimal},
		{'S', handle_custom_string},
		{'p', handle_pointer},
		{'\0', NULL}
	};
	int i = 0;

	while (fmt_hndlr[i].spc_chr != '\0')
	{
		if (fmt_hndlr[i].spc_chr == chr)
			return (fmt_hndlr[i].handle);
		i++;
	}
	return (NULL);
}

/**
 * reset_format_options - initializes fomrat options
 * @f: pointer to the format options
 *
 * Return: void
 */
void reset_format_options(fmt_opts_t *f)
{
	f->minus_flag = 0;
	f->plus_flag = 0;
	f->hash_flag = 0;
	f->zero_flag = 0;
	f->blank_flag = 0;
	f->width = 0;
	f->precision = 0;
	f->modifier = 0;
	f->spc_chr = 0;
}

