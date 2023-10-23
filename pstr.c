#include "monty.h"

/**
 * pstrFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void pstrFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv;
	(void)line_number;

	if (*Head == NULL)
		goto newline;

	trv = *Head;
	while (trv)
	{
		if (trv->n > 127 || trv->n <= 0)
			break;

		printf("%c", trv->n);
		trv = trv->next;
	}
newline:
	puts("");
}
