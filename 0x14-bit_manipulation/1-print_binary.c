#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @b: The number to be printed in binary.
 */
void print_binary(unsigned long int b)
{
	unsigned int num_bits = sizeof(b) * 8;
	unsigned int i;
	unsigned long int mask = 1UL << (num_bits - 1);

	while (mask > 0)
	{
		if (b & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;
	}

	if (b == 0)
		_putchar('0');
}

