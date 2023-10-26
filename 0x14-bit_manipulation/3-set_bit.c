#include "main.h"

/**
 * set_bit - function
 * @n: arg
 * @index: index
 *
 * Return: 1 or -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int S;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	S = 1 << index;
	*n = *n | S;
	return (1);
}

