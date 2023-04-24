#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

typedef struct ident_format
{
	char first_case;
	int (*func)(va_list);
} format_t;

#endif /*main.h*/
