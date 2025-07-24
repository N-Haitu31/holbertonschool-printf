#include "main.h"

/**
 * print_oct - Prints a signed octal (for %o)
 * @args: Variadic arguments with integer to print
 * Return: Character count printed octal
 */
int print_oct(va_list args)

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
			buffer[i++] = (n % 8) + '0';
			n /= 8;
		}
	}
	while (i > 0)
	{
		i--;
		count += write(1, &buffer[i], 1);
	}
	return (count);
}
