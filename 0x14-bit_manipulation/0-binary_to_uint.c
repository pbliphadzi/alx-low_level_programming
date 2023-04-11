#include "main.h"


unsigned int binary_to_uint(const char *biny)
{
    unsigned int result = 0;
    int length, n;
    
    if (biny == NULL)
        return 0;
    
    length = strlen(biny);
    
    for (n = 0; n < length; n++) {
        if (biny[n] != '0' && biny[n] != '1')
            return 0;
        
        result <<= 1;
        if (biny[n] == '1')
            result += 1;
    }
    
    return result;
}

