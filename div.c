#include "monty.h"

/**
 * divFnc - push number to list
 *
 * @head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void divFnc(stack_t **head, unsigned int line_number)
{
	stack_t *trv = *head;
	size_t len = 0, div;

	while (trv)
		trv = trv->next, len++;

	/* check the lenght of satck first */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freeStack(*head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}

	trv = *head;
	if (trv->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeStack(*head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	div = (trv->next->n / trv->n);
	*head = trv->next;
	(*head)->n = div;
	free(trv);
}

