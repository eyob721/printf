#include "main.h"

/**
 * format_integer - used to format all integer conversions, i.e. signed,
 *					unsigned, octal, hexadecimal and pointers as well.
 * @str: the converted integer string
 * @prefix: prefix for the integer
 * @f: pointer to the format data
 *
 * Return: pointer to the formatted outut, or NULL if memory allocation fails
 */
char *format_integer(char *str, char *prefix, fmt_data_t *f)
{
	fmt_out_data_t fod;
	int int_len, precision_is_set;

	/* Initialize format output data */
	fod.fmt_out = NULL;
	fod.str = str;
	fod.pre = prefix;
	fod.str_len = _strlen(str);
	fod.pre_len = _strlen(prefix);
	fod.pad = ' ';
	fod.jst = 'r';

	/* Step 1: Determine format output length */
	int_len = fod.str_len + fod.pre_len;
	fod.fmt_len = MAX(int_len, MAX(f->width, f->precision));
	precision_is_set = fod.fmt_len == f->precision;
	if (precision_is_set)
		fod.fmt_len += fod.pre_len;

	/* Step 2: Determine padding  and justification */
	if (precision_is_set || (f->zero_flag == 1 && f->minus_flag == 0))
		fod.pad = '0';
	if (f->minus_flag == 1)
		fod.jst = 'l';

	/* Step 3: Allocate memory for format outut */
	fod.fmt_out = malloc(sizeof(char) * (fod.fmt_len + 1));
	if (fod.fmt_out == NULL)
		return (NULL);

	/* Step 4: Write format output */
	fod.fmt_out[fod.fmt_len] = '\0';
	_memset(fod.fmt_out, fod.pad, fod.fmt_len);
	write_format_output(&fod);
	return (fod.fmt_out);
}

/**
 * write_format_output - used to write the given string on the newly allocated
 *						 format output, based on the formatting preferences
 *						 i.e. justification and padding
 * @fop: pointer to the format output data
 *
 * Return: void
 */
void write_format_output(fmt_out_data_t *fop)
{
	/* For zero padding */
	if (fop->pad == '0')
	{
		_memcpy(fop->fmt_out, fop->pre, fop->pre_len);
		_memcpy(fop->fmt_out + (fop->fmt_len - fop->str_len),
				fop->str, fop->str_len);
		return;
	}
	/* For default blank padding */
	switch (fop->jst)
	{
		case 'l':
			_memcpy(fop->fmt_out, fop->pre, fop->pre_len);
			_memcpy(fop->fmt_out + fop->pre_len, fop->str, fop->str_len);
		break;
		case 'r':
			_memcpy(fop->fmt_out + (fop->fmt_len - (fop->pre_len + fop->str_len)),
					fop->pre, fop->pre_len);
			_memcpy(fop->fmt_out + (fop->fmt_len - fop->str_len),
					fop->str, fop->str_len);
		break;
	}
}
