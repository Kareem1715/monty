#include "monty.h"

/**
 * pallFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void pallFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	(void)line_number;

	while (trv)
	{
		printf("%d\n", trv->n);
		trv = trv->next;
	}
}
