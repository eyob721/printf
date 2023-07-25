#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define NORMAL 0
#define CONVERSION 1

/* 10 (max no of digits) + 1 (for -/+ sign) + 1 (for '\0') = 12 */
#define INT_BUF_SIZE 12
/* 11 = 11 (max no of digits) + 1 (for '\0') */
#define OCT_BUF_SIZE 12
/* 9 = 8 (max no of digits) + 1 (for '\0') */
#define HEX_BUF_SIZE 9
/* 10 = 9 (max no of digits) + 1 (for '\0') */
#define UINT_BUF_SIZE 10
/* 17 = 16 (max no of digits) + 1 (for '\0') */
#define PTR_BUF_SIZE 17

/**
 * struct format_options - data structure for format options
 * @minus_flag: used to check if - flag is set
 * @plus_flag: used to check if + flag is set
 * @hash_flag: used to check if # flag is set
 * @zero_flag: used to check if 0 flag is set
 * @blank_flag: used to check if blank(' ') flag is set
 * @width: field width value
 * @precision: precision value
 * @modifier: length modifier value
 * @spc_chr: specifier character
 */
typedef struct format_options
{
	int minus_flag;
	int plus_flag;
	int hash_flag;
	int zero_flag;
	int blank_flag;
	int width;
	int precision;
	char modifier;
	char spc_chr;
} fmt_opts_t;

/**
 * struct format_handler - data structure for conversion event
 *						   handler functions
 * @spc_chr: conversion specifier
 * @handle: conversion handler function
 */
typedef struct format_handler
{
	char spc_chr;
	int (*handle)(va_list, fmt_opts_t *, char *, int *);
} fmt_hndlr_t;

/* Library utilities 1 */
int _putchar(char c);
void _puts(char *str);
int _islower(int c);
int _isupper(int c);

/* Library utilities 2 */
int _isalpha(int c);
int _isdigit(int c);
int _abs(int x);
int _atoi(char *s);

/* Library utilities 3 */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);

/* Library utilities 4 */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);

/* Library utilities 5 */
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);

/* Format option utilities */
void check_flag(char **s, fmt_opts_t *f);
void check_width(char **s, fmt_opts_t *f);
void check_precision(char **s, fmt_opts_t *f);
void check_modifier(char **s, fmt_opts_t *f);
void check_specifier(char **s, fmt_opts_t *f);

/* Integer converison utilities */
char *convert_int_to_str(int num, char *buf, int buf_size);
char *convert_uint_to_base_str(int base, unsigned int num, char ltr_case,
							char *buf, int buf_size);
char *convert_addr_to_hex_str(void *addr, char *buf, int buf_size);

/* Buffer utilities */
int _putchar_buf(char c, char *buf, int *ctr);
int _puts_buf(char *str, char *buf, int *ctr);

/* _printf implementation function */
int _printf(const char *format, ...);

/* _printf function utilities */
char *get_specifier(char *s, fmt_opts_t *f);
int (*get_specifier_handler(char chr))(va_list, fmt_opts_t *, char *, int *);
void reset_format_options(fmt_opts_t *f);

/* Conversion handler functions */
int handle_char(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_string(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_percent(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_integer(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_binary(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_unsigned(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_octal(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_hexadecimal(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_custom_string(va_list args, fmt_opts_t *f, char *buf, int *ctr);
int handle_pointer(va_list args, fmt_opts_t *f, char *buf, int *ctr);

#endif
