#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'a';
	char cH = 'A';

	while (ch <= 'z');
	{
		putchar(ch);
		ch++;
	}

	while (cH <= 'Z')
	{
		putchar('cH');
		cH++;
	}
	putchar(\n);

	return (0);
}

