#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer
 *
 * Return: value
 */
int pop_listint(listint_t **head)
{
	listint_t *t;
	int i;

	if (!head || !*head)
		return (0);
	i = (*head)->n;
	t = (*head)->next;
	free(*head);
	*head = t;

	return (i);
}
