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
	(void)line_number; /* Not used var */

	trv = *Head;
	while (trv)
	{
		if (trv->n > 127 || trv->n <= 0)/* all char in ascii */
			break;

		printf("%c", trv->n); /* Print char */
		trv = trv->next;
	}
	puts(""); /* If head empty or at end of func */
}
