#include "main.h"

/**
 * format_character_output - used to format character and string conversions
 * @str: string to be formatted
 * @fmt_len: integer pointer, used to pass by reference the value of the format
 *			 length back to the handler function
 * @f: pointer to the format data
 *
 * Return: pointer to the formatted output, or NULL if memory allocation fails
 * Description:
 *		- For character formatting we need to send the value of the format
 *		  output length back to the handler function, so that we can print only
 *		  the first 'n' bytes of that length
 *		- For strings first we have to determine the how many characters we
 *		  are going to print from 'str', based on the precision given, then we
 *		  determine the format length.
 */
char *format_character_output(char *str, int *fmt_len, fmt_data_t *f)
{
	fmt_out_data_t fod;
	int precision_is_set;

	/* Initialize format output data */
	fod.fmt_out = NULL;
	fod.pre = "";
	fod.str = str;
	fod.str_len = _strlen(str);
	fod.pre_len = 0;
	fod.pad = ' ';
	fod.jst = 'r';

	/* Step 1: Determine format output length */
	precision_is_set = f->precision >= 0;
	/* Truncate 'str' if precision is set and is less than the length of 'str'*/
	if (precision_is_set && f->precision < fod.str_len)
		fod.str_len = f->precision;
	fod.fmt_len = MAX(fod.str_len, f->width);

	/* Step 2: Determine justification */
	if (f->minus_flag == 1)
		fod.jst = 'l';

	/* Step 3: Allocate memory for format output */
	fod.fmt_out = malloc(sizeof(char) * (fod.fmt_len + 1));
	if (fod.fmt_out == NULL)
		return (NULL);

	/* Step 4: Write format output */
	fod.fmt_out[fod.fmt_len] = '\0';
	_memset(fod.fmt_out, fod.pad, fod.fmt_len);
	write_format_output(&fod);
	*fmt_len = fod.fmt_len;
	return (fod.fmt_out);
}

/**
 * format_integer_output - used to format all integer conversions, i.e. signed,
 *						   unsigned, octal, hexadecimal and pointers as well.
 * @str: the converted integer string
 * @prefix: prefix for the integer
 * @f: pointer to the format data
 *
 * Return: pointer to the formatted output, or NULL if memory allocation fails
 */
char *format_integer_output(char *str, char *prefix, fmt_data_t *f)
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

	/* Step 3: Allocate memory for format output */
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
 * Description: In case of an empty string, it also must be printed on the
 *				format output.
 */
void write_format_output(fmt_out_data_t *fop)
{
	/**
	 * If the converted string is an empty string,
	 * then you must write the null byte and count it as well
	 */
	if (*(fop->str) == '\0')
	{
		fop->fmt_len = fop->fmt_len != 0 ? fop->fmt_len - 1 : 0;
		fop->fmt_out[fop->fmt_len] = '\0';
		fop->fmt_len++;
		return;
	}
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

/*
 * NOTE: THIS IS HOW THE FORMATTING IS DONE
 *
 * Okay so basically formatting contains the following parts
 *			- converted string, (could be an integer type converted to a string,
 *			  a character cast to a string, or a string)
 *			- format length
 *			- padding character
 *			- justification
 *			- prefix (for integer conversions)
 *
 *	So the steps that are taken in formatting an output is
 *
 *	Step 1: Determine the format length
 *			- The format length is the maximum of the three values below
 *					- width,
 *					- precision, or
 *					- length of the converted string
 *			- For the string conversions, the precision is not used to determine
 *			  the length of the format field, but it tells us how many
 *			  characters from the string to put on that format field. So if the
 *			  precision given is less than the length of the given string then
 *			  the string must be truncated. Otherwise if the precision is
 *			  larger, then the string will written on the format field as-is.
 *	Step 2: Determine the padding
 *			- The padding depends on the precision, the zero flag and the minus
 *			  flag
 *			- The default padding character is a blank (' ')
 *			- The padding character, can be set to '0', if the precision is
 *			  specified, or if the zero is flag is set but the minus flag is not
 *			  set.
 *			- If the zero padding is set, justification doesn't matter. See the
 *			  note below
 *	Step 3: Determine the justification
 *			- The default justification is to the right
 *			- It can be set to the left, if the minus flag is set
 *	Step 4: Based on the format length we allocate memory
 *	Step 5: Write the converted string, on the allocated memory, based on the
 *			formatting options
 *
 *			- For all integer formatting (except for pointers), we have to take
 *			  care of prefixes
 *			- prefixes are signs ('+', '-', ' '), or number format indicators
 *			  ('0', '0x', '0X') that are written before the number
 *			- the prefixes are written differently based on the padding and
 *			  justification options used
 *			- When zero padding is used, no justification is applied, the syntax
 *			  is as follows:
 *
 *						[prefix][padding][number]
 *
 *				e.g. -7284 -> with zero padding -> [-000007284]
 *
 *			- So even justification will have no effect when zero padding is
 *			  used because the padding is put in the middle of the prefix and
 *			  the number, which pushes the prefix and the number to the field
 *			  ends.
 *			- And when blank padding is used, justification will be applied and
 *			  the syntax is as follows:
 *
 *					left justify	[prefix][number][padding]
 *					right justify	[padding][prefix][number]
 *
 *				e.g. left justify:	[-7284      ]
 *					 right justify: [      -7284]
 *
 * So these are the formatting steps that are taken to implement printf
 *
 *
 * Hope this helps :)
 */
