#include "printf.h"
#include <stdarg.h>

/**
 * _dprintf - implementation of dprintf function
 * @format: format string
 * @fd: file descriptor to write output to
 *
 * Return:
 *		- number of characters printed, or
 *		- -1 if there is an output error
 * Description:
 *		- Assume format syntax will be valid going in
 *		- If format syntax is invalid, then it goes into NORMAL state and
 *		  prints the characters as-is
 */
int _dprintf(int fd, const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL ||
		_strcmp((char *)format, "%") == 0 ||
		_strcmp((char *)format, "% ") == 0 ||
		fd == -1)
		return (-1);
	va_start(args, format);
	printed_chars += _vdprintf(fd, format, args);
	va_end(args);
	return (printed_chars);
}
