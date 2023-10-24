#include "lists.h"

/**
 * add_nodeint_end - adds a node
 * @head: pointer
 * @n: arg
 *
 * Return: pointer
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *i;
	listint_t *t = *head;

	i = malloc(sizeof(listint_t));
	if (!i)
		return (NULL);
	i->n = n;
	i->next = NULL;
	if (*head == NULL)
	{
		*head = i;
		return (i);
	}
	while (t->next)
		t = t->next;
	t->next = i;
	return (i);
}
