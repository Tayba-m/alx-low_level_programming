
#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints buffer
 * @b: buffer
 * @size: size
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int o = 0, x, a;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (o < size)
	{
		x = size - o < 10 ? size - o : 10;

		printf("%08x: ", o);
		for (a = 0; a < 10; a++)
		{
			if (a < x)
				printf("%02x", *(b + o + a));
			else
				printf("  ");
			if (a % 2)
			{
				printf(" ");
			}
		}
		for (a = 0; a < x; a++)
		{
			int c = *(b + o + a);

			if (c < 32 || c > 132)
			{
			c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		o += 10;
	}
}

