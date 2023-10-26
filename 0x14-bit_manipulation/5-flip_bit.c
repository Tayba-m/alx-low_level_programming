#include "main.h"

/**
 * flip_bits - function
 * @n: arg
 * @m: arg
 *
 * Return: value
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int c;
	unsigned long int e = n ^ m;
	int cb = 0, t;

	for (t = 63; t >= 0; t--)
	{
		c = e >> t;
		if (c & 1)
			cb++;
	}

	return (cb);
}
