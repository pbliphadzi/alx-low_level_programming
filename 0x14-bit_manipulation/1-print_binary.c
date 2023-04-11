#include "main.h"

void print_binary(unsigned long int n)
{
    unsigned long int MASK = 1UL << ((sizeof(unsigned long int) * 8) - 1);
    int bit = 0;
    
    while (MASK) {
     	   if (n & MASK)
            putchar('1');
      	  else
            putchar('0');
        
        		MASK >>= 1;
        		bit++;
        
        if (bit % 4 == 0 && MASK)
            putchar(' ');
    }
}

