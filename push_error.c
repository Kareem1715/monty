#include "monty.h"


/**
 * push_error - close file, free and exit
 *
 * @Head: list to free it
 * @line_number: number of line in error
 *
 * Return: Nothing
 */
void push_error(stack_t *Head, unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	freeStack(Head);
	fclose(gVar.fileName);
	exit(EXIT_FAILURE);
}
