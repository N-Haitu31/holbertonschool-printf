#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <limits.h>
/**
 * _printf - copy printf function
 * @format: string with format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, handle;
	int count = 0;
	va_list args;
	spec_t specs[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent}, {'d', print_int},
		{'i', print_int}, {'b', print_bin}, {'o', print_oct}, {'\0', NULL},
	};
	va_start(args, format);
	if ((format == NULL || format[i] == '%') && format[i + 1] == '\0')
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			handle = 0;
			for (j = 0; specs[j].spec != '\0'; j++)
			{
				if (format[i] == specs[j].spec)
				{
					count += specs[j].f(args);
					handle = 1;
					break;
				}
			}
			if (!handle)
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
