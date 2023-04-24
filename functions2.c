#include <stdio.h>
#include "main.h"
int print_bin(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	int counter = 0, i = 0, bin_array[32];

	if (num == 0)
	{
		counter++;
		putchar('0');
	}
	else
	{
		while (num > 0)
		{
			bin_array[i] = num % 2;
			num /= 2;
			counter++;
		}
		for (i = counter - 1; i >= 0; i++)
		{
			putchar(bin_array[i] + '0');
			counter++;
		}
	}
	return (counter);
}
