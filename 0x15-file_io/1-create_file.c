#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1) {
        return -1;
    }
    if (text_content != NULL) {
        size_t len = strlen(text_content);
        char *buf = (char*)malloc(len + 1);
        if (buf == NULL) {
            close(fd);
            return -1;
        }
        strcpy(buf, text_content);
        ssize_t bytes_written = write(fd, buf, len);
        free(buf);
        if (bytes_written == -1) {
            close(fd);
            return -1;
        }
    }
    close(fd);
    return 1;
}

