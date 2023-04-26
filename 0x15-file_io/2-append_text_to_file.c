#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Name of the file to append to.
 * @txcontent: Text content to append to the file.
 * Return: If successful, 1. Otherwise, -1.
 */
int append_text_to_file(const char *filename, char *txcontent)
{
    int filedescrip;
    ssize_t bywrite;
    
    if (filename == NULL)
        return -1;
    
    filedescrip = open(filename, O_WRONLY | O_APPEND);
    if (filedescrip == -1)
        return -1;
    
    if (txcontent != NULL)
    {
        bywrite = write(filedescrip, txcontent, strlen(txcontent));
        if (bywrite == -1)
        {
            close(filedescrip);
            return -1;
        }
    }
    
    close(filedescrip);
    return 1;
}

