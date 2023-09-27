#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer params
 * Return: 0
 */

void rev_string(char *n)
{
	int a, b = 0;
	char t;

	while (*(n + a) != '\0')
	{
		a++;
	}
	a--;
	for (b = 0; b < a; b++, a--)
	{
		t = *(n + b);
		*(n + b) = *(n + a);
		*(n + a) = t;
	}
}
/**
 * infinite_add - add 2 numbers together
 * @n1: text representation of 1st number to add
 * @n2: text representation of 2nd number to add
 * @r: pointer to buffer
 * @size_r: buffer size
 * Return: pointer to calling function
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int o_f = 0, a = 0, b = 0, digits = 0;
	int v1 = 0, v2 = 0, t_t = 0;

	while (*(n1 + a) != '\0')
		a++;

	while (*(n2 + b) != '\0')
		b++;
	a--;
	b--;

	if (b >= size_r || a >= size_r)
		return (0);

	while (b >= 0 || a >= 0 || o_f == 1)
	{
		if (a < 0)
		v1 = 0;
		else
		v1 = *(n1 + a) - '0';
		if (b < 0)
		v2 = 0;
		else
		v2 = *(n2 + b) - '0';
		t_t = v1 + v2 + o_f;
		if (t_t >= 10)
		o_f = 1;
		else
		o_f = 0;
		if (digits >= (size_r - 1))
		return (0);
		*(r + digits) = (t_t % 10) + '0';
		digits++;
		b--;
		a--;
	}
		if (digits == size_r)
		return (0);

		*(r + digits) = '\0';
		rev_string(r);
		return (r);
}
