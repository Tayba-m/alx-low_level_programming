#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that multiplies two numbers.
 * @argc: number of arguments
 * @argv: array with the arguments
 *
 * Return: always 0
 **/

int main(int argc, char *argv[])
{
	int m = 0;
	char ch[] = "Error";

	if (argc != 3)
	{
		printf("%s\n", ch);
		return (1);
	}
	m = atoi(argv[1]) * atoi(argv[2]);
	printf("%i\n", m);
	return (0);
}
