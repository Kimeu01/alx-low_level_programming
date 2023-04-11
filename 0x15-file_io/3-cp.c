#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is for storing char
 *
 * Return: A pointers that shows a buffer that has been allocated
 */
char *create_buffer(char *file)
{
	char *bufer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}
/**
 * close_file - closes the file descriptor
 * @fd: The file descriptor to be closed
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
		exit(100)
	}
}
/**
 * main - Copy the content of a file to another file
 * @argc: The number of arguments given
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 if sucess
 *
 * Description: If argument count is wrong, exit code 97
 *              If file_from is non-existent or unreadable, exit code 98
 *              If file_to cannot be created or written, exit code 99
 *              If file_to or file_from cannot be closed, exit code 100
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t nchars, nwr;
	char buffer(1024);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s/n", "Usage cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O-RDONLY);
	file_to = open(argv[2], O-CREAT | O_WRONLY | O_TRUNC | 0-APPEND, 0664);
	error_file(file_from, file_to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(file_from, buffer, 1024);
		if (nchars == -1)
			error_file(0, -1 argv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d/n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit (100);
	}
	return (0);
}
