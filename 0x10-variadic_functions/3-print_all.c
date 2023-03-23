#include <stdarg.h>
#include <stdio.h>

void print_all(const char * const format, ...)
{
    va_list args;
    va_start(args, format);

    char *str;
    int i;
    char c;
    float f;

    while (*format)
    {
        switch (*format)
        {
            case 'c':
                c = (char) va_arg(args, int);
                printf("%c", c);
                break;
            case 'i':
                i = va_arg(args, int);
                printf("%d", i);
                break;
            case 'f':
                f = (float) va_arg(args, double);
                printf("%f", f);
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                    printf("(nil)");
                else
                    printf("%s", str);
                break;
            default:
                break;
        }

        if (*(format + 1))
            printf(", ");

        format++;
    }

    printf("\n");

    va_end(args);
}
