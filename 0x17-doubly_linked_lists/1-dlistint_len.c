#include "lists.h"

/**
 * dlistint_len - get number of nodes
 * @h: arg
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int n = 0;

	while (h)
	{
		n += 1;
		h = h->next;
	}
	return (n);
}
