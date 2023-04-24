#include <stdio.h>
#include <stdarg.h>
#include "main.h"
<<<<<<< HEAD
=======

>>>>>>> fab77769c9db3aeff66a2350d9ab8385c81ef7b4
/**
 * print_c - handle c case after % in _printf
 * @ap: argument pointer
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

int print_mod(va_list ap __attribute__((unused)))
{
	putchar('%');
	return (1);
}

/**
 * _printf - prints based on format
 * @format: identifier to look for
 * Return: length of string
 */


int _printf(const char *format, ...)
{
	va_list ap;
	int i, counter = 0;

	format_t formats[] = {
		{ 'c', print_c }, { 's', print_s }, { '%', print_mod }, { 0, NULL }
	};
	if (format == NULL)
	{
		return (-1);
	}
	va_start(ap, format);

	for ( ; *format; format++)
	{
		if (*format != '%')
		{
			putchar(*format);
			counter += 1;
		}
		else
		{
			format++;
			for (i = 0; formats[i].first_case; i++)
			{
				if (formats[i].first_case == *format)
					counter += formats[i].func(ap);
			}
		}
	}

	va_end(ap);
	return (counter);
}
