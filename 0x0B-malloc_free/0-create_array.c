#include <stdlib.h>
#include "main.h"

/**
 * *create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: size of the array to create
 * @c: char to initialize the array c
 * Return:(Success), NULL
 */
char *create_array(unsigned int size, char c)
{
	char *poi;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);

	poi = malloc(sizeof(char) * size);

	if (poi == NULL)
		return (0);

	while (i < size)
	{
		poi[i] = c;
		i++;
	}

	return (poi);
}
