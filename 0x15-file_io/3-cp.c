#include <stdio.h>
#include <stdlib.h>

/*
 * fileclose - close a file and set its pointer to NULL
 *
 * This function takes a pointer to a file pointer and closes the file
 * if it is open. It also sets the pointer to NULL to avoid dangling
 * references.
 *
 * Parameters:
 *   file: pointer to a file pointer
 *
 * Returns:
 *   void
 */
void fileclose(FILE **file) {
    if (*file) {
        fclose(*file);
        *file = NULL;
    }
}

/*
 * main - copy the content of a file to another file
 *
 * This program takes two command-line arguments: the name of the file
 * to copy from and the name of the file to copy to. It copies the
 * content of the first file to the second file, creating it if it
 * doesn't exist and overwriting it if it does.
 *
 * Parameters:
 *   argc: the number of command-line arguments
 *   argv: an array of strings containing the command-line arguments
 *
 * Returns:
 *   int (0 if success, 97-100 if error)
 */
int main(int argc, char *argv[]) {
    char *from_path, *to_path;
    FILE *from_file, *to_file;
    char buf[1024];
    size_t num_read;

    if (argc != 3) {
        printf("Usage: cp file_from file_to\n");
        return 1;
    }
    
    from_path = argv[1];
    to_path = argv[2];
    
    from_file = fopen(from_path, "rb");
    if (!from_file) {
        printf("Error: Can't read from file %s\n", from_path);
        return 1;
    }
    
    to_file = fopen(to_path, "wb");
    if (!to_file) {
        printf("Error: Can't write to file %s\n", to_path);
        fileclose(&from_file);
        return 1;
    }
    
    while ((num_read = fread(buf, 1, sizeof(buf), from_file)) > 0) {
        if (fwrite(buf, 1, num_read, to_file) != num_read) {
            printf("Error: Can't write to file %s\n", to_path);
            fileclose(&from_file);
            fileclose(&to_file);
            return 1;
        }
    }
    
    if (ferror(from_file)) {
        printf("Error: Can't read from file %s\n", from_path);
        fileclose(&from_file);
        fileclose(&to_file);
        return 1;
    }
    
    fileclose(&from_file);
    fileclose(&to_file);
    return 0;
}

