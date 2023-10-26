
#include "main.h"

/**
 * binary_to_uint - function 
 * @b: pointer
 *
 * Return: unsigned int or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n;
	int t;

	n = 0;
	if (!b)
		return (0);
	for (t = 0; b[t] != '\0'; t++)
	{
		if (b[t] != '0' && b[t] != '1')
			return (0);
	}
	for (t = 0; b[t] != '\0'; t++)
	{
		n <<= 1;
		if (b[t] == '1')
			n += 1;
	}
	return (n);
}

