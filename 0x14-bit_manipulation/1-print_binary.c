#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long integer
 */
void print_binary(unsigned long int n)
{
	unsigned long int bit = 1UL << ((sizeof(unsigned long int) * 8) - 1);
	int has_printed = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (bit > 0)
	{
		if ((n & bit) == bit)
		{
			_putchar('1');
			has_printed = 1;
		}
		else if (has_printed == 1)
		{
			_putchar('0');
		}
		bit = bit >> 1;
	}
}

