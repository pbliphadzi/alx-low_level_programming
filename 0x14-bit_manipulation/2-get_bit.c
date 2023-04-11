#include "main.h"

int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
	        return -1;
    
		    unsigned long int MASK = 1UL << (sizeof(unsigned long int) * 8 - 1);
		    for (int i = 0; i < index; i++)
        MASK >>= 1;
    
    return (n & MASK) ? 1 : 0;
}

