#include "monty.h"

/**
 * subFnc - push number to list
 *
 * @head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void subFnc(stack_t **head, unsigned int line_number)
{
	stack_t *trv = *head;
	size_t len = 0, sub;

	while (trv)
		trv = trv->next, len++;

	/* check the lenght of satck first */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freeStack(*head);
		free(gVar.instruction);
		fclose(gVar.fileName);
		exit(EXIT_FAILURE);
	}
	trv = *head;
	sub = (trv->next->n - trv->n);
	*head = trv->next;
	(*head)->n = sub;
	free(trv);
}
