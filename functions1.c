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

int print_num_helper(int num)
{
	char digit;
	int counter;

	if (num == 0)
		return (0);

	counter = 1 + print_num_helper(num / 10);
	digit = num % 10 + '0';
	putchar(digit);
	return (counter);
}


int print_num(va_list ap)
{
	int counter = 0;
	int num = va_arg(ap, int);

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	else if (num < 0)
	{
		putchar('-');
		counter = 1 + print_num_helper(-num);
	}
	else 
	{
		counter = print_num_helper(num);
	}
	return (counter);
}
