#include <stdio.h>
#include "main.h"
/**
 * main - program that prints its name, followed by a new line
 * @argc: number of arguments
 * @argv: array with the arguments
 *
 * Return: always 0
 **/

int main(int argc, char const *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
