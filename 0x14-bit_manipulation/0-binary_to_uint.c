#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary string to an unsigned integer
 * @b: binary string
 *
 * Return: converted unsigned integer, or 0 if invalid binary string
 */

unsigned int binary_to_uint(const char *b)
{
    unsigned int decimal = 0;
    int i, j;
    int len;

    if (!b)
        return (0);

    len = strlen(b);
    for (i = 0, j = len - 1; i < len; i++, j--)
    {
        if (b[i] == '1')
        {
            decimal += (1 << j);
        }
        else if (b[i] != '0')
        {
            return (0);
        }
    }
    return (decimal);
}

