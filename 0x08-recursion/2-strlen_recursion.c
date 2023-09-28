#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: arg
 * Return: length
 */

int _strlen_recursion(char *s)

{
	int longth = 0;

	if (*s)
	{
		longth++;
		longth += _strlen_recursion(s + 1);
	}
	return (longth);
}
