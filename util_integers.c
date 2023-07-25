#include "main.h"

/**
 * convert_int_to_str - a function that converts a signed integer to a string
 * @num: number to be converted
 * @buf: buffer for the converted string
 * @buf_size: size of the buffer
 *
 * Return: skips all the zeros, and returns the start of the converted integer
 *		   in the buffer
 * Description: The result is written on the given buffer starting
 *				from the back to the front.
 *				e.g. -7284 is written in each iteration as follows:
 *					iter 1: 000000000004
 *					iter 2: 000000000084
 *					iter 3: 000000000284
 *					iter 4: 0000000-7284
 */
char *convert_int_to_str(int num, char *buf, int buf_size)
{
	char *start, *digit = "0123456789";
	int i = buf_size - 1, rem, is_negative;

	buf[i] = '\0';
	is_negative = num < 0 ? 1 : 0;
	do {
		--i;
		rem = _abs(num % 10);
		buf[i] = digit[rem];
		start = buf + i;
		num /= 10;
	} while (num != 0 && i >= 0);
	if (is_negative && i >= 0)
	{
		buf[--i] = '-';
		start = buf + i;
	}
	return (start);
}

/**
 * convert_uint_to_base_str - a function that converts an unsigned integer to
 *							  any base in string format
 * @base: base of conversion (i.e. decimal, binary, octal or hexadecimal)
 * @num: number to be converted
 * @ltr_case: letter case of the digits, 'c' for CAPITAL, ot 'l' for lowercase
 * @buf: buffer for the converted string
 * @buf_size: size of the buffer
 *
 * Return: skips all the hashes, and returns the start of the converted integer
 *		   in the buffer
 * Description: The result is written on the given buffer starting
 *				from the back to the front.
 *				e.g. 1101 (in binary) is written in each iteration as
 *					iter 1: ###########1
 *					iter 2: ##########01
 *					iter 3: #########101
 *					iter 4: ########1101
 */
char *convert_uint_to_base_str(int base, unsigned int num, char ltr_case,
							char *buf, int buf_size)
{
	char *start, *digit = "0123456789abcedf";
	int i, rem;

	if (ltr_case == 'C')
		digit = "0123456789ABCDEF";
	i = buf_size - 1;
	buf[i] = '\0';
	do {
		--i;
		rem = num % base;
		buf[i] = digit[rem];
		start = buf + i;
		num /= base;
	} while (num != 0 && i >= 0);
	return (start);
}

