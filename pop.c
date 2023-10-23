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
	stack_t *trv = *Head;

	if (!*Head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeStack(*Head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	*Head = trv->next;
	free(trv);
}
