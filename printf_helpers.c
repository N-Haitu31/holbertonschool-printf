#include "main.h"
/**
 * print_char - Prints a single character
 * @args: Variadic arguments with character to print
 * Return: The number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
 * print_str - Prints a character string
 * @args: Variadic argument list containing a pointer to the string to print
 * Return: Number of characters printed, handling NULL as (null)
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
 * print_percent - Prints a literal percentage character ('%')
 * @args: Variadic argument list (unused)
 * Return: The number of characters printed (always 1)
 */
int print_percent(va_list args)
{
	char c = '%';
	(void)args;
	return (write(1, &c, 1));
}
/**
 * print_int - Prints a signed integer (for %d or %i)
 * @args: Variadic arguments with integer to print
 * Return: Character count printed; manages positive, negative, and INT_MIN
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
 * print_bin - Prints a signed binary (for %b)
 * @args: Variadic arguments with integer to print
 * Return: Character count printed binay
 */
int print_bin(va_list args)

{
	long int n = va_arg(args, int);
	char buffer[12];
	int i = 0, count = 0;

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
