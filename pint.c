#include "monty.h"

/**
 * pintFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void pintFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;

	if (!*Head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (trv)
		printf("%d\n", trv->n);
}
