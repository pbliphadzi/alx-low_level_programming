#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

/*
 * filecopy - copy the content of one file to another file
 *
 * Parameters:
 *   from_path: path to the source file
 *   to_path: path to the destination file
 *
 * Returns: int (0 if success, non-zero if error)
 */
int filecopy(const char* from_path, const char* to_path) {
    int fd_from, fd_to, rd, wr;
    char buf[BUFSIZE];

    fd_from = open(from_path, O_RDONLY);
    if (fd_from == -1) {
        perror(from_path);
        return 1;
    }

    fd_to = open(to_path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        perror(to_path);
        close(fd_from);
        return 1;
    }

    while ((rd = read(fd_from, buf, BUFSIZE)) > 0) {
        wr = write(fd_to, buf, rd);
        if (wr != rd) {
            perror(to_path);
            close(fd_from);
            close(fd_to);
            return 1;
        }
    }

    if (rd == -1) {
        perror(from_path);
        close(fd_from);
        close(fd_to);
        return 1;
    }

    if (close(fd_from) == -1) {
        perror(from_path);
        return 1;
    }

    if (close(fd_to) == -1) {
        perror(to_path);
        return 1;
    }

    return 0;
}

/*
 * main - entry point of the program
 *
 * Parameters:
 *   argc: the number of command-line arguments
 *   argv: an array of strings containing the command-line arguments
 *
 * Returns: int (0 if success, non-zero if error)
 */
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        return 1;
    }

    return filecopy(argv[1], argv[2]);
}

