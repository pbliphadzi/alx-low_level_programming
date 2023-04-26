#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @b: The number to be printed in binary.
 */
void print_binary(unsigned long int b)
{
    if (b == 0) 
    {
        _putchar('0');
        return;
    }
    
    int num_bits = sizeof(b) * 8;
    int found_one = 0;
    
    for (int i = num_bits - 1; i >= 0; i--)
    {
        unsigned long int mask = 1UL << i;
        
        if (b & mask)
        {
            found_one = 1;
            _putchar('1');
        }
        else if (found_one)
        {
            _putchar('0');
        }
    }
    
    return;
}

