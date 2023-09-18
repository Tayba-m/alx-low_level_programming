#include "main.h"
/**
 * swap_int - swaps the values of two integers
 * @a: a pointer that swaps the values
 * @b :a pointer that swap the values
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
