#include <stdlib.h>
#include "main.h"

/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 * Return: (Success), NULL (Error)
 */
char *str_concat(char *s1, char *s2)
{
	char *con;
	int t, y;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	t = y = 0;
	while (s1[t] != '\0')
		t++;
	while (s2[y] != '\0')
		y++;
	con = malloc(sizeof(char) * (t + y + 1));
	if (con == NULL)
		return (NULL);

	t = y = 0;
	while (s1[t] != '\0')
	{
		con[t] = s1[t];
		t++;
	}
	while (s2[y] != '\0')
	{
		con[t] = s2[y];
		t++, y++;
	}
	con[t] = '\0';
	return (con);
}
