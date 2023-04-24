#include <stdio.h>
#include <stdarg.h>
#include "main.h"



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
		{ 'c', print_c }, { 's', print_s }, { '%', print_mod }, {'d', print_num}, {'i', print_num}, { 0, NULL }
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
