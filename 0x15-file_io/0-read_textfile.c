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
    int fd;
    ssize_t br, bw, tbw;
    char buf[BUFFER];

    if (filename == NULL)
        return 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    tbw = 0;
    while (letters > 0) {
        br = read(fd, buf, BUFFER < letters ? BUFFER : letters);
        if (br == -1)
        {
            close(fd);
            return 0;
        }
        if (br == 0)
            break;
        bw = write(STDOUT_FILENO, buf, br);
        if (bw == -1)
        {
            close(fd);
            return tbw;
        }
        tbw += bw;
        letters -= bw;
    }

    close(fd);
    return tbw;
}
