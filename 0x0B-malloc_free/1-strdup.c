#include <stdlib.h>
#include "main.h"

/**
 * *_strdup - copies the string given as parameter
 * @str: string to duplicate
 * Return:(Success), NULL
 */
char *_strdup(char *str)
{
	char *poi;
	unsigned int i, tt;

	i = 0;
	tt = 0;

	if (str == NULL)
		return (NULL);

	while (str[tt])
		tt++;

	poi = malloc(sizeof(char) * (tt + 1));

	if (poi == NULL)
		return (NULL);

	while ((poi[i] = str[i]) != '\0')
		i++;

	return (poi);
}

