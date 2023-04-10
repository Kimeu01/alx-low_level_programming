#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a textfile then it prints to POSIX stdout
 * @filename: A pointer to file name
 * @letters: The numbers of letters that the functions reads and prints
 *
 * Return: if function fails or filename is NULL - 0.
 *O/w - the actual number of bytes the function can read ad print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}

