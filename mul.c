#include "monty.h"

/**
 * mulFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void mulFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	size_t n = 0, mul;

	while (trv)
		trv = trv->next, n++;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	trv = *Head;
	mul = (trv->next->n * trv->n);
	*Head = trv->next;
	(*Head)->n = mul;
	free(trv);
}
