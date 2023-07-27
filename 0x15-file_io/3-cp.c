#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * check_arguments - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_io - checks for I/O errors and closes file descriptors if necessary
 * @result: result of an I/O operation
 * @file: file name associated with the operation
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check_io(ssize_t result, char *file, int fd_from, int fd_to)
{
	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't process %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_close - checks that file descriptors were closed properly
 * @result: result of the close operation
 * @fd: file descriptor
 *
 * Return: void
 */
void check_close(int result, int fd)
{
	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t len_read, len_written;
	char buffer[1024];
	mode_t file_perm;

	check_arguments(argc);

	fd_from = open(argv[1], O_RDONLY);
	check_io((ssize_t)fd_from, argv[1], -1, -1);

	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_io((ssize_t)fd_to, argv[2], fd_from, -1);

	len_read = 1024;
	while (len_read == 1024)
	{
		len_read = read(fd_from, buffer, 1024);
		check_io(len_read, argv[1], fd_from, fd_to);

		len_written = write(fd_to, buffer, len_read);
		if (len_written != len_read)
			len_written = -1;
		check_io(len_written, argv[2], fd_from, fd_to);
	}

	check_close(close(fd_to), fd_to);
	check_close(close(fd_from), fd_from);

	return (0);
}

