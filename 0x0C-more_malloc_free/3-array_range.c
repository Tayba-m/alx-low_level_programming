
#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *poi;
	int a, s;

	if (min > max)
		return (NULL);
	s = max - min + 1;
	poi = malloc(sizeof(int) * s);
	if (poi == NULL)
		return (NULL);
	for (a = 0; min <= max; a++)
		poi[a] = min++;
	return (poi);
}
