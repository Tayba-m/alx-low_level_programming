#include "main.h"

/**
 * _pow - function
 * @base: arg
 * @power: arg
 *
 * Return: value
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned int t;
	unsigned long int n = 1;

	for (t = 1; t <= power; t++)
		n *= base;
	return (n);
}

/**
 * print_binary - prints
 * @n: number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int f = 0;
	unsigned long int d, c;

	d = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (d != 0)
	{
		c = n & d;
		if (c == d)
		{
			f = 1;
			_putchar('1');
		}
		else if (f == 1 || d == 1)
		{
			_putchar('0');
		}
		d >>= 1;
	}
}

