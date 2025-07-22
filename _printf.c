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
	int i = 0;
	int count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	if (format[i] == '%' && format[i + 1] == '\0')
		return (-1);
	while (format[i] != '\0')
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

			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);

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

/**
 * print_int - print integer
 * @args : list arguments
 *
 * Return: count
 */

int print_int (va_list args)
{
	int count = 0;
	long int n = va_arg(args, int);
	char buffer[12];
	int i = 0;

	if (n == INT_MIN)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	while (i > 0)
	{
		i--;
		count += write(1, &buffer[i], 1);
	}

	return (count);
}
