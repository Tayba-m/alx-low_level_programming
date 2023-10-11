#include <stdio.h>
#include "dog.h"

/**
 * print_dog - print_dog
 * @d: pointar
 *
 * Return: nothing
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		printf("Name: %s\n", d->name ? name : "(nil)");
		printf("Age: %f\n", age);
		printf("Owner: %s\n", d->owner ? owner : "(nil)");
	}
}
