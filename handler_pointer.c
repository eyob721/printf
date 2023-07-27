#include "main.h"
#include <stdarg.h>

/**
 * handle_pointer - handler function for pointer conversion
 * @f: pointer to the format data
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
int handle_pointer(fmt_data_t *f, char *buf, int *ctr)
{
	int printed_chars = 0;
	char *ptr_str, ptr_buf[PTR_BUF_SIZE] = "################";
	void *addr = va_arg(f->args, void *);

	if (addr == NULL)
		ptr_str = "(nil)";
	else
		ptr_str = convert_addr_to_hex_str(addr, ptr_buf, PTR_BUF_SIZE);
	printed_chars += _puts_buf(ptr_str, buf, ctr);
	return (printed_chars);
}
