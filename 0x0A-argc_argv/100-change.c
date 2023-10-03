#include <stdio.h>
#include "main.h"

/**
 * main - prints minimum number coins to make change for an amount of money.
 * @argc: number of arguments
 * @argv: array with the arguments
 *
 * Return: always 0
 **/

int main(int argc, char *argv[])
{
	int d = 0, coi = 0;
	char c[] = "Error";

	if (argc != 2)
	{
		printf("%s\n", c);
		return (1);
	}
	d = atoi(argv[1]);
	while (d >= 25)
	{
		d -= 25;
		coi++;
	}
	while (d >= 10)
	{
		d -= 10;
		coi++;
	}
	while (d >= 5)
	{
		d -= 5;
		coi++;
	}
	while (d >= 2)
	{
		d -= 2;
		coi++;
	}
	if (d == 1)
		coi++;
	printf("%d\n", coi);
	return (0);
}
