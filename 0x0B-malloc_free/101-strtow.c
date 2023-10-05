#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int f = 0, t, m = 0;

	for (t = 0; s[t] != '\0'; t++)
	{
		if (s[t] == ' ')
			f = 0;
		else if (f == 0)
		{
			f = 1;
			m++;
		}
	}
	return (m);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **mat, *t;
	int i, k = 0, l = 0, w, c = 0, s, e;

	while (*(str + l))
		l++;
	w = count_word(str);
	if (w == 0)
		return (NULL);
	mat = (char **) malloc(sizeof(char *) * (w + 1));
	if (mat == NULL)
		return (NULL);
	for (i = 0; i <= l; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				e = i;
				t = (char *) malloc(sizeof(char) * (c + 1));
				if (t == NULL)
					return (NULL);
				while (s < e)
					*t++ = str[s++];
				*t = '\0';
				mat[k] = t - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			s = i;
	}
	mat[k] = NULL;
	return (mat);
}

