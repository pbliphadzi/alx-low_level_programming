#include "main.h"
#define BUFFER 1024

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 *
 * @filename
 * @letters
 *
 * Return: If successful, the number of bytes read and printed. Otherwise, 0.
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
        return 0;

    FILE *FP = FILEOPEN(filename, "r");
    if (FP == NULL)
        return 0;

    char *buffer = malloc(1024);
    if (buffer == NULL)
    {
        FILECLOSE(FP);
        return 0;
    }

    ssize_t BYTEREAD = FILEREAD(buffer, sizeof(char), 1024, FP);
    buffer[BYTEREAD] = '\0';

    FILECLOSE(FP);

    if (BYTEREAD == 0)
    {
        free(buffer);
        return 0;
    }

    ssize_t BYTEWRITE = BYTEWRITE(buffer, sizeof(char), BYTEREAD, stdout);
    free(buffer);

    if (BYTEWRITE != BYTEREAD)
        return 0;

    return BYTEREAD;
}

