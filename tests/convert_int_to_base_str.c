#include "main.h"
#include <limits.h>
#include <stdio.h>

#define UINT_BUF_SIZE 10 /* 10 + 1 for '\0' */
#define BIN_BUF_SIZE 33 /* 32 + 1 for '\0' */
#define OCT_BUF_SIZE 12 /* 11 + 1 for '\0' */
#define HEX_BUF_SIZE 9 /* 8 + 1 for '\0' */

/**
 * convert_uint_to_base_str - a function that converts an unsigned integer to
 *							  any base in string format
 * @base: base of conversion (i.e. decimal, binary, octal or hexadecimal)
 * @num: number to be converted
 * @lit_case: letter case of the digits, 'C' for CAPITAL, ot 'l' for lowercase
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

int main(void)
{
	char base_buf[UINT_BUF_SIZE] ={0};
	char *base_str;

	base_str = convert_uint_to_base_str(10, 0,'l', base_buf, UINT_BUF_SIZE);
	printf("%s\n", base_str);

	base_str = convert_uint_to_base_str(10, 105,'l', base_buf, UINT_BUF_SIZE);
	printf("%s\n", base_str);

	base_str = convert_uint_to_base_str(10, -105,'l', base_buf, UINT_BUF_SIZE);
	printf("%s\n", base_str);

	base_str = convert_uint_to_base_str(10, UINT_MAX,'l', base_buf, UINT_BUF_SIZE);
	printf("%s\n", base_str);
	return (0);
}
