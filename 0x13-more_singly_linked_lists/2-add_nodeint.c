#include "lists.h"

/**
 * add_nodeint - adds a new node at linked list
 * @head: pointer
 * @n: arg
 *
 * Return: pointer
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *t;

	t = malloc(sizeof(listint_t));
	if (!t)
	return (NULL);

	t->n = n;
	t->next = *head;
	*head = t;

	return (t);
}
