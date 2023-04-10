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
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97)
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	}

	while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
