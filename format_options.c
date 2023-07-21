#include "main.h"
/**
 * check_flag - checkes if the current character at position pointed by 's' in
 *		the format string is a flag character
 *@s: position on the format string
 *@f: pointer to the format options
 *return: void
 */
void check_flag(char **s, fmt_opts_t *f)
{
	int is_flag = 1;

	while (**s != '\0')
	{
		switch (**s)
		{
		case '-':
			f->minus_flag = 1;
		break;
		case '+':
			f->plus_flag = 1;
		break;
		case '0':
			f->zero_flag = 1;
		break;
		case '#':
			f->hash_flag = 1;
		break;
		case ' ':
			f->blank_flag = 1;
		break;
		default:
			is_flag = 0;
		}
		if (is_flag)
			++(*s);
	}
}

