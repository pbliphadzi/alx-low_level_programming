#include "main.h"
#define BUFFER 2048

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters to read from the file.
 * Return: If successful, the number of bytes read and printed. Otherwise, 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    int filedescip;
    ssize_t btread, btwrite, tbtwrite;
    char buffer[BUFFER];

    if (filename == NULL)
        return 0;

    filedescip = open(filename, O_RDONLY);
    if (filedescip == -1)
        return 0;

    tbtwrite = 0;
    while (letters > 0) {
        btread = read(filedescip, buffer, BUFFER < letters ? BUFFER : letters);
        if (btread == -1)
        {
            close(filedescip);
            return 0;
        }
        if (btread == 0)
            break;
        btwrite = write(STDOUT_FILENO, buffer, btread);
        if (btwrite == -1)
        {
            close(filedescip);
            return tbtwrite;
        }
        tbtwrite += btwrite;
        letters -= btwrite;
    }

    close(filedescip);
    return tbtwrite;
}
