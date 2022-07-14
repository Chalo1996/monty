#include "monty.h"

/**
 * add_dnodeint - adds node at the beginning of the linked
 *                                  list.
 * @head: pointer to the top node.
 * @n: data to be inserted.
 *
 * Return: pointer to the top.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	tmp = (stack_t *)malloc(sizeof(stack_t));

	if (tmp == NULL)
		return (NULL);

	if (*head == NULL)
	{
		tmp->n = n;
		tmp->next = NULL;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}

	(*head)->prev = tmp;
	tmp->n = n;
	tmp->next = *head;
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
  * delete_dnodeint_at_index - deletes a node at an index.
  * @head: pointer to the top node.
  * @index: the index of the node to delete.
  *
  * Return: 1 if true, -1 otherwise.
  */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp1;
	stack_t *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp1 = *head;

	if (index == 0)
	{
		*head = tmp1->next;
		if (tmp1->next != NULL)
			tmp1->next->prev = NULL;
		free(tmp1);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (tmp1 == NULL)
			return (-1);
		tmp1 = tmp1->next;
		i++;
	}
	tmp2 = (tmp1->next)->next;
	if (tmp1->next->next != NULL)
		tmp1->next->next->prev = tmp1;
	free(tmp1->next);
	tmp1->next = tmp2;

	return (1);
}

/**
  * add_dnodeint_end - adds a node at the end of the linked list.
  * @head: pointer to the top node.
  * @n: data to be inserted in the list.
  *
  * Return: pointer to the top.
  */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *tmp3;

	tmp3 = (stack_t *)malloc(sizeof(stack_t));

	if (tmp3 == NULL)
		return (NULL);

	tmp3->n = n;

	if (*head == NULL)
	{
		tmp3->next = NULL;
		tmp3->prev = NULL;
		*head = tmp3;
		return (tmp3);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = tmp3;
	tmp3->prev = tmp;
	tmp3->next = NULL;
	return (tmp3);
}

/**
  * free_dlistint - free the memory.
  * @head: pointer to the top node.
  *
  */

void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
