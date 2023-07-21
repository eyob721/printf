#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct fmt_opts - data structure for format options
 * @minus_flag: used to check if - flag is set
 * @plus_flag: used to check if + flag is set
 * @hash_flag: used to check if # flag is set
 * @zero_flag: used to check if 0 flag is set
 * @blank_flag: used to check if blank(' ') flag is set
 * @width: field width value
 * @precison: precison value
 * @modifier: length modifier value
 */
typedef struct fmt_opts
{
	int minus_flag;
	int plus_flag;
	int hash_flag;
	int zero_flag;
	int blank_flag;
	int width;
	int precison;
	char *modifier;
} fmt_opts_t;	

int _printf(const char *format, ...);

/* utility lib 1 */
int _putchar(char c);
void _puts(char *str);
int _islower(int c);
int _isupper(int c);

/* utility lib 2 */
int _isalpha(int c);
int _isdigit(int c);
int _abs(int x);
int _atoi(char *s);

/* utility lib 3 */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);

/* utility lib 4 */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);

/* utility lib 5 */
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);

#endif
