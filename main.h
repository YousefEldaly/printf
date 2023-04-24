#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_c(va_list ap);
int print_s(va_list ap);
int print_mod(va_list ap);
int print_num(va_list ap);

typedef struct ident_format
{
	char first_case;
	int (*func)(va_list);
} format_t;

#endif /*main.h*/
