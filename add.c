#include "monty.h"

/**
 * addFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void addFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	size_t n = 0;

	while (trv)
		trv = trv->next, n++;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*Head)->next->n += (*Head)->n;
	trv = (*Head)->next;
	free(*Head);
	*Head = trv;
}

