#include "main.h"

/**
 * get_endianness - checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
    unsigned int k = 1;
    char *r = (char *)&k;

    if (*r)
        return 1;
    else
        return 0;
}

