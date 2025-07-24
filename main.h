#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct format_specifier - define a struct for format specifier
 * @spec : characters specifier
 * @f : pointer function
 *
 * Return : void
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
#endif
