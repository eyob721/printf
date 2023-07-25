#include "main.h"
#include <limits.h>
#include <stdio.h>

#define INT_BUF_SIZE 14
/* 12 (max no of digits) + 1 (for -/+ sign) + 1 (for '\0') = 14 */

/**
 * convert_int_to_str - a function that converts a signed integer to string
 * @num: number to be converted
 * @buf: buffer for the converted string
 * @buf_size: size of the buffer
 *
 * Return: skips all the zeros, and returns the start of the converted integer in the
 *		   buffer
 * Description: The result is written on the given buffer starting
 *				from the back to the front.
 *				e.g. 7284 is written in each iteration as
 *					iter 1: ###########4
 *					iter 2: ##########84
 *					iter 3: #########284
 *					iter 4: ########7284
 */
char *convert_int_to_str(int num, char *buf, int buf_size)
{
	char *start, *digit = "0123456789";
	int i, rem, is_negative;

	i = buf_size - 1;
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

int main(void)
{
	char int_buf[INT_BUF_SIZE] ={0};
	char *int_str;

	int_str = convert_int_to_str(0, int_buf, INT_BUF_SIZE);
	printf("%s\n", int_str);
	int_str = convert_int_to_str(7284, int_buf, INT_BUF_SIZE);
	printf("%s\n", int_str);
	int_str = convert_int_to_str(-7284, int_buf, INT_BUF_SIZE);
	printf("%s\n", int_str);
	int_str = convert_int_to_str(INT_MAX, int_buf, INT_BUF_SIZE);
	printf("%s\n", int_str);
	int_str = convert_int_to_str(INT_MIN, int_buf, INT_BUF_SIZE);
	printf("%s\n", int_str);
	return (0);
}
