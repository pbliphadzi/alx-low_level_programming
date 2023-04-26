#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @b: The number to be printed in binary.
 */
void print_binary(unsigned long int b)
{
    if (b == 0) 
    {
        putchar('0');
        return;
    }
    
    unsigned int num_bits = sizeof(b) * 8;
    unsigned int found_one = 0;
    unsigned int i;
    
    for (i = num_bits - 1; i >= 0; i--)
    {
        unsigned long int mask = 1UL << i;
        
        if (b & mask)
        {
            found_one = 1;
            putchar('1');
        }
        else if (found_one)
        {
            putchar('0');
        }
    }
    
    return;
}

