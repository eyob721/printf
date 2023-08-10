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
	int printed_chars = 0, fmt_case = 0, ctr = 0;
	int (*handle)(fmt_data_t *, char *, int *);
	fmt_data_t fdata;

	if (format == NULL || _strcmp((char *)format, "%") == 0 ||
			_strcmp((char *)format, "% ") == 0)
		return (-1);
	va_start(fdata.args, format);
	while (*ptr != '\0')
		switch (fmt_case)
		{
		case NORMAL:
			if (*ptr == '%')
			{
				fmt_case = CONVERSION;
				break;
			}
			printed_chars += _putchar_buf(*ptr, fmt_buf, &ctr);
			++ptr;
		break;
		case CONVERSION:
			fmt_case = NORMAL;
			initialize_format_data(&fdata);
			spc = get_specifier(ptr + 1, &fdata);
			if (spc != NULL) /* Valid format syntax */
			{
				handle = get_specifier_handler(*spc);
				printed_chars += handle(&fdata, fmt_buf, &ctr);
				ptr = spc + 1;
				break;
			}
			printed_chars += print_invalid_syntax(&ptr, &fdata, fmt_buf, &ctr);
		break;
		}
	printed_chars += _putchar_buf(BUFFER_FLUSH, fmt_buf, &ctr);
	va_end(fdata.args);
	return (printed_chars);
}
/**
 * get_specifier - a function that gets the specifier position while also
 *				   checking that format data set in the format string are set
 *				   in the correct format syntax.
 * @s: pointer to the position in the format string, next to the '%' character
 * @f: pointer to the format data
 *
 * Return: NULL if the format syntax is invalid, or a pointer to the conversion
 *		   specifier position in the format string
 * Description: The correct format syntax is as follows:
 *				%[flags][width][.precision][modifier]specifier
 *				NOTE: all other options are optional, except the specifier
 */
char *get_specifier(char *s, fmt_data_t *f)
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
int (*get_specifier_handler(char chr))(fmt_data_t *, char *, int *)
{
	fmt_hndlr_t fmt_hndlr[] = {
		{'%', handle_percent},
		{'c', handle_char},
		{'s', handle_string},
		{'d', handle_integer},
		{'i', handle_integer},
		{'u', handle_unsigned},
		{'o', handle_octal},
		{'x', handle_hexadecimal},
		{'X', handle_hexadecimal},
		{'p', handle_pointer},
		{'b', handle_custom_binary},
		{'S', handle_custom_string},
		{'r', handle_custom_reverse_string},
		{'R', handle_custom_rot13},
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
 * initialize_format_data - initializes format data
 * @f: pointer to the format data
 *
 * Return: void
 */
void initialize_format_data(fmt_data_t *f)
{
	f->minus_flag = 0;
	f->plus_flag = 0;
	f->hash_flag = 0;
	f->zero_flag = 0;
	f->blank_flag = 0;
	f->width = 0;
	f->precision = -1;
	f->modifier = 0;
	f->spc_chr = 0;
	f->invalid_spc = NULL;
	f->fmt_opts_set = 0;
}

/**
 * print_invalid_syntax - prints the invalid synatx to the format Buffer
 * @p: a double pointer to the current position on the format string
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed
 */
int print_invalid_syntax(char **p, fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;

	while (**p != '\0' && *p <= f->invalid_spc)
	{
		if (**p == f->modifier)
		{
			++(*p); /* Skip it if is a modifier */
			continue;
		}
		printed_chars += _putchar_buf(**p, buf, ctr);
		++(*p);
	}
	return (printed_chars);
}
