#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define NORMAL 0
#define CONVERSION 1

/* 20 = 19 (max no of digits for LONG_SIGNED) + 1 (for '\0') */
#define INT_BUF_SIZE 20
/* 23 = 22 (max no of digits for LONG_UNSIGNED) + 1 (for '\0') */
#define OCT_BUF_SIZE 23
/* 17 = 16 (max no of digits LONG_UNSIGNED) + 1 (for '\0') */
#define HEX_BUF_SIZE 17
/* 21 = 20 (max no of digits for LONG_UNSIGNED) + 1 (for '\0') */
#define UINT_BUF_SIZE 21
/* 17 = 16 (max no of digits) + 1 (for '\0') */
#define PTR_BUF_SIZE 17
/* 33 = 32 (max no of digits) + 1 (for '\0') */
#define BIN_BUF_SIZE 33

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/**
 * struct format_data - data structure to hold format data
 * @args: list of optional arguments given
 * @minus_flag: used to check if - flag is set
 * @plus_flag: used to check if + flag is set
 * @hash_flag: used to check if # flag is set
 * @zero_flag: used to check if 0 flag is set
 * @blank_flag: used to check if blank(' ') flag is set
 * @width: field width value
 * @precision: precision value
 * @modifier: length modifier value
 * @spc_chr: specifier character
 * @invalid_spc: pointer used to save the invalid specifier position
 */
typedef struct format_data
{
	va_list args;
	int minus_flag;
	int plus_flag;
	int hash_flag;
	int zero_flag;
	int blank_flag;
	int width;
	int precision;
	char modifier;
	char spc_chr;
	char *invalid_spc;
} fmt_data_t;

/**
 * struct format_field_data - data structure to hold data for formatting
 *							  converted string output
 * @fmt_field: pointer to the formatted field
 * @str: converted string, to be formatted
 * @pre: prefix of the converted string (i.e. minus and plus signs, or '0x'
 *		 prefixes for hexadecimal strings, ... e.t.c)
 * @field_len: length of the format field string
 * @str_len: length of the converted string
 * @pre_len: length of the prefix string
 * @pad: padding character
 * @jst: justification of the formatted output
 * @prc: the given precision value
 */
typedef struct format_field_data
{
	char *fmt_field;
	char *str;
	char *pre;
	int field_len;
	int str_len;
	int pre_len;
	char pad;
	int jst;
	int prc;
} fmt_field_data_t;
/**
 * struct format_handler - data structure for conversion event
 *						   handler functions
 * @spc_chr: conversion specifier
 * @handle: conversion handler function
 */
typedef struct format_handler
{
	char spc_chr;
	int (*handle)(fmt_data_t *, char *, int *);
} fmt_hndlr_t;

/* Library 1 */
int _isdigit(int c);
int _abs(int x);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);

/* Library 2 */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);

/* Format syntax utilities */
void check_flag(char **s, fmt_data_t *f);
void check_width(char **s, fmt_data_t *f);
void check_precision(char **s, fmt_data_t *f);
void check_modifier(char **s, fmt_data_t *f);
void check_specifier(char **s, fmt_data_t *f);

/* Integer converison utilities */
char *convert_int_to_str(long int num, char *buf, int buf_size);
char *convert_uint_to_base_str(int base, unsigned long int num, char ltr_case,
							char *buf, int buf_size);
char *convert_addr_to_hex_str(void *addr, char *buf, int buf_size);

/* Buffer utilities */
int _putchar_buf(char c, char *buf, int *ctr);
int _puts_buf(char *str, char *buf, int *ctr);
int _puts_nbytes_buf(char *str, int n, char *buf, int *ctr);

/* Formatting utilities */
char *format_character_output(char *str, int *fmt_len, fmt_data_t *f);
void write_character_format(fmt_field_data_t *fd);
char *format_integer_output(char *int_str, char *prefix, fmt_data_t *f);
void write_integer_format(fmt_field_data_t *fd);

/* _printf implementation function */
int _printf(const char *format, ...);

/* _printf function utilities */
char *get_specifier(char *s, fmt_data_t *f);
int (*get_specifier_handler(char chr))(fmt_data_t *, char *, int *);
void initialize_format_data(fmt_data_t *f);
int print_invalid_syntax(char **p, fmt_data_t *f, char *buf, int *ctr);

/* Conversion handler functions */
int handle_char(fmt_data_t *f, char *buf, int *ctr);
int handle_string(fmt_data_t *f, char *buf, int *ctr);
int handle_percent(fmt_data_t *f, char *buf, int *ctr);
int handle_integer(fmt_data_t *f, char *buf, int *ctr);
int handle_unsigned(fmt_data_t *f, char *buf, int *ctr);
int handle_octal(fmt_data_t *f, char *buf, int *ctr);
int handle_hexadecimal(fmt_data_t *f, char *buf, int *ctr);
int handle_pointer(fmt_data_t *f, char *buf, int *ctr);
int handle_custom_string(fmt_data_t *f, char *buf, int *ctr);
int handle_custom_binary(fmt_data_t *f, char *buf, int *ctr);
int handle_custom_reverse_string(fmt_data_t *f, char *buf, int *ctr);
int handle_custom_rot13(fmt_data_t *f, char *buf, int *ctr);

#endif
