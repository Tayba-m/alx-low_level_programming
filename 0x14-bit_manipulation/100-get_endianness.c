#include "main.h"

/**
 * get_endianness - function
 *
 * Return: 0 or 1
 */
int get_endianness(void)
{
	char *m;
	int t = 1;

	m = (char *)&t;
	return (*m);
}
