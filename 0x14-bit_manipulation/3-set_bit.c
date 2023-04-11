#include "main.h"

int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return -1;
    
    unsigned long int MASK = 1UL << (sizeof(unsigned long int) * 8 - 1);
    	for (int I = 0; I < index; I++)
        	MASK >>= 1;
		*n |= MASK;
    
    return 1;
}

