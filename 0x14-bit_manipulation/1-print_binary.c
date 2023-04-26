#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 *
 * @n: The number to print in binary
 */

void print_binary(unsigned long int n)
{

    int size = sizeof(unsigned long int);


    for (int i = (size * 8) - 1; i >= 0; i--)
    {
 
        putchar((n & mask) ? '1' : '0');
    }
}

