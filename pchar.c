#include "monty.h"

/**
 * pcharFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void pcharFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv;
	(void)line_number;

	trv = *Head;
	if (!trv)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	if (trv->n > 127 || trv->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", trv->n);
}
