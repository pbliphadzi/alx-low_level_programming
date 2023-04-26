#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @b: A pointer to the bit.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int set_bit(unsigned long int *b, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return -1;
    
    *b |= 1UL << index;
    
    return 1;
}

