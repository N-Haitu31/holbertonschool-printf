#include "main.h"
/**
 * print_char - Imprime un caractère
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés (toujours 1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
 * print_str - Imprime une chaîne de caractères
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
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
 * print_percent - Imprime un pourcentage littéral (%)
 * @args: Liste d'arguments (ignoré)
 * Return: Nombre de caractères imprimés (toujours 1)
 */
int print_percent(va_list args)
{
	char c = '%';
	(void)args;
	return (write(1, &c, 1));
}
/**
 * print_int - Imprime un entier signé (%d ou %i)
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
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
