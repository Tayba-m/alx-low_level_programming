#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read file
 * @filename: file read
 * @letters: number of letters
 *
 * Return: write
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t v, write, read;

	v = open(filename, O_RDONLY);
	if (v == -1)
		return (0);
	buffer = malloc(letters * sizeof(char));
	read = read(v, buffer, letters);
	write = write(STDOUT_FILENO, buffer, read);

	free(buffer);
	close(v);
	return (write);
}
