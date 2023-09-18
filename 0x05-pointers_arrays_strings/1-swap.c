#include <stdio.h>
#include <main.h>
/**
 * void swap_int - set the integer to 402
 * @a @b: a pointer that swaps the values
 *
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
   int c;

	c = *a;
	*a = *b;
	*b = c;
}
}
