#include "main.h"

/**
 * handle_rot13- handle custom rot13
 * @buf: a pointer to the format buffer
 * @ctr: current index/counter in the buffer
 *
 * Return: number of characters printed to stdout
 */
char *rot13(char *str)
{
  int i, j;

  char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

  for (i = 0; str[i] != '\0'; i++)
  {
    for (j = 0; input[j] != '\0'; j++)
    {
      if (str[i] == input[j])
      {

        printed_chars += _putchar_buf(output[j], buf, ctr) 

        break;
      }
    }
  if (input[j] == '\0')
        printed_chars += _putchar_buf(str[i], buf, ctr) 

  }
  return (str);
}