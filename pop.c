#include "monty.h"
/**
 * popFunc - prints the top
 * @Head: stack head
 * @line_number: line_number error
 * Return: no return
*/
void popFunc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;

	if (!*Head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	*Head = trv->next;
	free(trv);
}
/**
 * swapFunc - adds the top two elements of the stack.
 * @Head: stack head
 * @line_number: line_number
 * Return: no return
*/
void swapFunc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	size_t n = 0, tmpVal;

	while (trv)
		trv = trv->next, n++;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	trv = *Head;
	tmpVal = trv->n;
	trv->n = trv->next->n;
	trv->next->n = tmpVal;
}
/**
 * addFunc - adds the top two elements of the stack.
 * @Head: stack head
 * @line_number: line_number
 * Return: no return
*/
void addFunc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;
	size_t n = 0;

	while (trv)
		trv = trv->next, n++;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*Head)->next->n += (*Head)->n;
	trv = (*Head)->next;
	free(*Head);
	*Head = trv;
}
void nopFunc(__attribute__((unused)) stack_t **Head, __attribute__((unused)) unsigned int line_number)
{
	return;
}
