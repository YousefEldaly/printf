#include <stdio.h>
#include "main.h"

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
