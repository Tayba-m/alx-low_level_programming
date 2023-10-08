#include <stdlib.h>
#include "main.h"
/**
 * string_nconcat - function that concatenates two strings.
 * @s1:arg
 * @s2:arg
 * @n:arg
 *
 * Return:pointer shall point to a newly allocated space in memory.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *poi;
	unsigned int a = 0, b = 0, len_s1 = 0, len_s2 = 0;

	while (s1 && s1[len_s1])
		len_s1++;
	while (s2 && s2[len_s2])
		len_s2++;

	if (n < len_s2)
		poi = malloc(sizeof(char) * (len_s1 + n + 1));
	else
		poi = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!poi)
		return (NULL);
	while (a < len_s1)
	{
		poi[a] = s1[a];
		a++;
	}
	while (n < len_s2 && a < (len_s1 + n))
		poi[a++] = s2[b++];
	while (n >= len_s2 && a < (len_s1 + len_s2))
		poi[a++] = s2[b++];
	poi[a] = '\0';
	return (poi);
}
