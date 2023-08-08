#include "printf.h"
#include <stdarg.h>

/**
 * _vdprintf - implementation of vdprintf function
 * @format: format string
 * @fd: file descriptor to write output to
 * @args: pointer to optiiona aruments
 *
 * Return:
 *		- number of characters printed, or
 *		- -1 if there is an output error
 * Description:
 *		- Assume format syntax will be valid going in
 *		- If format syntax is invalid, then it goes into NORMAL state and
 *		  prints the characters as-is
 */
int _vdprintf(int fd, const char *format, va_list args)
{
	char *ptr = (char *)format, *spc, fmt_buf[BUFFER_SIZE] = {0};
	int printed_chars = 0, fmt_case = 0, ctr = 0;
	int (*handle)(fmt_data_t *, char *, int *);
	fmt_data_t fdata;

	fdata.fd = fd;
	va_copy(fdata.args, args);
	while (*ptr != '\0')
		switch (fmt_case)
		{
		case NORMAL:
			if (*ptr == '%')
			{
				fmt_case = CONVERSION;
				break;
			}
			printed_chars += _putchar_buf(fdata.fd, *ptr, fmt_buf, &ctr);
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
	printed_chars += _putchar_buf(fdata.fd, BUFFER_FLUSH, fmt_buf, &ctr);
	va_end(fdata.args);
	return (printed_chars);
}
