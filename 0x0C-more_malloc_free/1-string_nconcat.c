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
	char *ptr;
	int a, b, l_s1, l_s2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (l_s1 = 0; s1[l_s1] != '\0'; l_s1++)
		;
	for (l_s2 = 0; s2[l_s2] != '\0'; l_s2++)
		;
	ptr = malloc(l_s1 + n + 1);

	if (ptr == NULL)
		return (NULL);

	for (a = 0; s1[a] != '\0'; a++)
		ptr[a] = s1[a];
	for (b = 0; b < n; b++)
	{
		ptr[a] = s2[b];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
