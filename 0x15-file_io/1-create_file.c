#include "main.h"

/**
 * create_file - Creates file.
 * @filename: pointer name of the file
 * @text_content: pointer to a string
 *
 * Return:  - -1 or 1.
 */
int create_file(const char *filename, char *text_content)
{
	int v, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}
	v = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(v, text_content, len);

	if (v == -1 || w == -1)
		return (-1);

	close(v);
	return (1);
}
