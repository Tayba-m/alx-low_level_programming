#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new
 * @head: pointer
 * @idx: index
 * @n: arg
 *
 * Return: pointer or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *t = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);
	new->n = n;
	new->next = NULL;


	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	for (i = 0; t && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = t->next;
			t->next = new;
			return (new);
		}
		else
			t = t->next;
	}
	return (NULL);
}
