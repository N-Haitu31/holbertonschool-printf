#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - copy printf function
 * @format: string with format specifiers
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);

			else if (format[i] == 's')
				count += print_str(args);

			else if (format[i] == '%')
				count += print_percent();

			else
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

/**
* print_char - print character
* @args : list arguments
*
* Return: 1
*/
int print_char (va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
* print_str - print string
* @args : list arguments
*
* Return: numbers characters
*/
int print_str(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	return (write(1, str, len));
}

/**
* print_percent - print "%"
*
* Return: 1
*/
int print_percent(void)
{
	char c = '%';

	return (write(1, &c, 1));
}
