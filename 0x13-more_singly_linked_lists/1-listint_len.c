#include "lists.h"

/**
 * listint_len - returns the number
 * @h: arg
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t t = 0;

	while (h)
	{
		t++;
		h = h->next;
	}

	return (t);
}

