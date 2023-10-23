#include "monty.h"


/**
 * modFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void modFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	size_t n = 0, mod;

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
	if (trv->n == 0) /* divide by zero */
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	mod = (trv->next->n % trv->n);
	*Head = trv->next;
	(*Head)->n = mod;
	free(trv);
}
