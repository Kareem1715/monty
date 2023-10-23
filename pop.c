#include "monty.h"

/**
 * popFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void popFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head; /* point to first node */

	if (*Head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	*Head = trv->next; /* Make head point to the next of trv */
	free(trv); /* Free trv or free first node */
}
