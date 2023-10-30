#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int v);

/**
 * creates_buffer - function
 * @file: name of the file buffer
 *
 * Return: pointer
 */
char *creates_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file
 * @fd: The file
 */
void close_file(int v)
{
	int C;

	C = close(v);

	if (C == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close v %d\n", v);
		exit(100);
	}
}

/**
 * main -  contents file to another file.
 * @argc: number of arguments
 * @argv: array of pointers arguments.
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int read, write, f, t;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	f = open(argv[1], O_RDONLY);
	read = read(from, buffer, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read f file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write = write(t, buffer, read);
		if (t == -1 || write == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write t %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read = read(f, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (read > 0);

	free(buffer);
	close_file(f);
	close_file(t);

	return (0);
}
