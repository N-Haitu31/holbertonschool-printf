#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct format_specifier - Maps a format specifier to its handling function
 * @spec : The character for the format specifier ('c', 's', '%', ...)
 * @f : Pointer to the function that handles printing for this specifier
 *
 */

typedef struct format_specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;
int _printf(const char *format, ...);
int print_char (va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_bin(va_list args);
int print_oct(va_list args);
#endif
