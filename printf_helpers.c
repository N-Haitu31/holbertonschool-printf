#include "main.h"
/**
 * print_char - Prints a single character ('%c')
 * @args: Contains the character to be printed (via variadic arguments)
 * Return: Always 1, because only one character is printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
 * print_str - Prints a string of characters ('%s')
 * @args: The string to be printed
 * Return: The number of characters printed, handling NULL as "(null)"
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	return (write(1, str, len));
}
/**
 * print_percent - Prints the '%' character
 * @args: Not used by this function
 * Return: Always 1, because only one character is printed
 */
int print_percent(va_list args)
{
	char c = '%';
	(void)args;
	return (write(1, &c, 1));
}
/**
 * print_int - Prints a signed integer ('%d' or '%i')
 * @args: The integer to print
 * Return: The number of character printed
 */
int print_int(va_list args)
{
	long int n = va_arg(args, int);
	char buffer[12];
	int i = 0, count = 0;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		buffer[i++] = '0';
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

/**
 * print_bin - Converts and prints an integer in binary format ('%b')
 * @args: The integer argument
 * Return: The count of binary characters printed
 */
int print_bin(va_list args)

{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[33];
	int i = 0, count = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 2) + '0';
			n /= 2;
		}
	}
	while (i > 0)
	{
		i--;
		count += write(1, &buffer[i], 1);
	}
	return (count);
}
