#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Name of the file to append to.
 * @text_content: Text content to append to the file.
 * Return: If successful, 1. Otherwise, -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t bw;
    
    if (filename == NULL)
        return -1;
    
    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return -1;
    
    if (text_content != NULL)
    {
        bw = write(fd, text_content, strlen(text_content));
        if (bw == -1)
        {
            close(fd);
            return -1;
        }
    }
    
    close(fd);
    return 1;
}
