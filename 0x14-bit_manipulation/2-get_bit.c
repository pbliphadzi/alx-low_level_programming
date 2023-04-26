#include <stdlib.h>
#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @b: The bit
 * @index: Index gets the value at - indices start at 0.
 
 * Return: If an error occurs - -1.
 */
int get_bit(unsigned long int b, unsigned int index)
{
    int *p_result;

    if (index >= sizeof(unsigned long int) * 8)
        return -1;

    p_result = malloc(sizeof(int));
    if (p_result == NULL) {
        return -1;
    }

    *p_result = (b >> index) & 1;

    int result = *p_result;
    free(p_result);

    return result;
}

