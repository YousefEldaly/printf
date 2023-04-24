#include <stdio.h>
#include "main.h"

/**
 * print_c -  handle c case after % in _printf
 * @ap: argument pointer
 * Return: 1
 */
int print_c(va_list ap)
{
	char c = va_arg(ap, int);

	putchar(c);
	return (1);
}

/**
 * print_s - handle s case after % in _printf
 * @ap: argument pointer
 * Return: the length of string
 */

int print_s(va_list ap)
{
	int counter = 0;
	char *str = va_arg(ap, char *);

	for ( ; *str; str++, counter++)
		putchar(*str);
	return (counter);
}
/**
 * print_mod - prints '%' to handle '%' case in _printf
 * @ap: just to match the standard of all format handling functions
 * Return: 1
 */

int print_mod(va_list ap __attribute__((unused)))
{
	putchar('%');
	return (1);
}
