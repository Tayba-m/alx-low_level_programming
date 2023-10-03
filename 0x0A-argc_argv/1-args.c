#include <stdio.h>
#include "main.h"

/**
 * main - program that prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array with the arguments
 * Return: always 0
 **/

int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
