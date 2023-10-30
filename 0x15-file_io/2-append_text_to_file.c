#include "main.h"

/**
 * append_text_to_file - Appends text at the end file
 * @filename: pointer to the file name
 * @text_content: string add to the end of file.
 *
 * Return: -1 or 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int open, write, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	open = open(filename, O_WRONLY | O_APPEND);
	write = write(open, text_content, len);

	if (open == -1 || write == -1)
		return (-1);

	close(open);

	return (1);
}
