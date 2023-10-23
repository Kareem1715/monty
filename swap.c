#include "monty.h"

/**
 * swapFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void swapFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	size_t n = 0, tmpVal;

	while (trv)
		trv = trv->next, n++;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	trv = *Head;
	tmpVal = trv->n;
	trv->n = trv->next->n;
	trv->next->n = tmpVal;
}
