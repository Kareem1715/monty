#include "monty.h"

/**
 * freeStack - free the list
 * @Head: the head point of list.
 * Return: Nothing
 */
void freeStack(stack_t *Head)
{
	stack_t *nxt;

	while (Head)
	{
		nxt = Head->next;
		free(Head);
		Head = nxt;
	}
}
