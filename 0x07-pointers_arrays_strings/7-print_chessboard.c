#include "main.h"

/**
 * print_chessboard - Entry point
 * @a: array
 * Return: Always 0 (Success)
 */

void print_chessboard(char (*a)[8])
{
	int x;
	int z;

	for (x = 0; x < 8; x++)
	{
		for (z = 0; z < 8; z++)
			_putchar(a[x][z]);
                _putchar('\n')
	}
}
