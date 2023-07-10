#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - creates a file
 * @filename: the name of the file
 * @txcont: string to write in the file
 * Return: 1 On success annd -1 on failure
 */

int create_file(const char *filename, char *txcont)
{
    int filedescrip, len;
    ssize_t bytes_written;

    if (filename == NULL)
        return (-1);

    if (txcont == NULL)
        txcont = "";

    filedescrip = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0600);
    if (filedescrip == -1)
        return (-1);

    len = strlen(txcont);
    bytes_written = write(filedescrip, txcont, len);
    if (bytes_written == -1)
    {
        close(filedescrip);
        return (0);
    }

    close(filedescrip);
    return (1);
}
