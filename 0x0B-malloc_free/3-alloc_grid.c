#include <stdlib.h>
#include "main.h"

/**
 * **alloc_grid - creates a two dimensional array of ints
 * @width: width of the matrix
 * @height: height of the matrix
 * Return:(Success) NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int **poi;
	int t, m;

	if (width <= 0 || height <= 0)
		return (NULL);
	poi = malloc(sizeof(int *) * height);
	if (poi == NULL)
		return (NULL);
	for (t = 0; t < height; t++)
	{
		poi[t] = malloc(sizeof(int) * width);
		if (poi[t] == NULL)
		{
			for (; t >= 0; t--)
				free(poi[t]);
			free(poi);
			return (NULL);
		}
	}
	for (t = 0; t < height; t++)
	{
		for (m = 0; m < width; m++)
			poi[t][m] = 0;
	}
	return (poi);
}
