#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to get bit from
 * @index: index of bit starting from 0
 * Return: value of bit at index, or -1 if an error occurred
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit_mask;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	bit_mask = 1UL << index;
	return ((n & bit_mask) ? 1 : 0);
}

