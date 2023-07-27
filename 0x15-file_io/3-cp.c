#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * copyFile - copies the content of one file to another
 * @fileFrom: the source file
 * @fileTo: the destination file
 * Return: void
 */
void copyFile(const char *fileFrom, const char *fileTo)
{
    int fdFrom = open(fileFrom, O_RDONLY);
    int fdTo = open(fileTo, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    if (fdFrom == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fileFrom);
        exit(98);
    }
    if (fdTo == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fileTo);
        exit(99);
    }

    while ((bytesRead = read(fdFrom, buffer, BUFFER_SIZE)) > 0)
    {
        bytesWritten = write(fdTo, buffer, bytesRead);
        if (bytesWritten == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fileTo);
            exit(99);
        }
    }

    if (bytesRead == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fileFrom);
        exit(98);
    }

    if (close(fdFrom) == -1 || close(fdTo) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
        exit(100);
    }
}

