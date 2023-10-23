#include "monty.h"


/**
 * nopFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void nopFnc(stack_t **Head, unsigned int line_number)
{
	int x = 2;
	(void)Head;
	(void)line_number;

	if (x > 0)
		x = 1;
}
