#include <stdio.h>
#include "main.h"

/**
 * main - program that adds positive numbers.
 * @argc: number of arguments
 * @argv: array with the arguments
 *
 * Return: always 0
 **/

int main(int argc, char *argv[])
{
	int i, sum = 0, r = 0;
	char ch[] = "Error", *find_letter;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			find_letter = argv[i];
			while (*find_letter != 0)
			{
				if (*find_letter < 47 || *find_letter > 57)
				{
					printf("%s\n", ch);
					return (1);
				}
				find_letter++;
			}
			r = atoi(argv[i]);
			sum += r;
		}
		printf("%d\n", sum);
	}
	else
		printf("%d\n", 0);
	return (0);
}
