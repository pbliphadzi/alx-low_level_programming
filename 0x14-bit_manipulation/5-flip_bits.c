#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip to get from one number to another
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xval = n ^ m;
	unsigned int num = 0;

	while (xval)
	{
		num += xval & 1;
		xval >>= 1;
	}

	return num;
}

