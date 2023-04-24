#include <stdio.h>
#include <stdarg.h>

/**
 * print_c - handle c case after % in _printf
 * @ap: argument pointer
 */
void print_c(va_list ap)
{
	 char c = va_arg(ap, int);

	 putchar(c);
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
 * _printf - prints based on format
 * @format: identifier to look for
 * Return: length of string
 */


int _printf(const char *format, ...)
{
	va_list ap;
	int counter = 0;

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
			if (*format == 'c')
			{
				print_c(ap);
				counter += 1;
			}
			else if (*format == 's')
			{
				counter += print_s(ap);
			}
			else if (*format == '%')
			{
				putchar('%');
			}
		}
	}

	va_end(ap);
	return (0);
}
