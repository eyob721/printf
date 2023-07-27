#include "main.h"

/**
 * handle_rev_string- handler function for reversing string
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
void rev_string(char *s)
{
  int i;

  for (i = _strlen(s) - 1; i >= 0; --i)
  printed_char += _putchar_buf(s[i], buf, ctr);
}