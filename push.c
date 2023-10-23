#include "monty.h"

/**
 * pushFnc - push number to list
 *
 * @Head: the head point of list.
 * @line_number: line number for error.
 *
 * Return: Nothing
 */
void pushFnc(stack_t **Head, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (gVar.buffer[1])
	{
		newNode->n = atoi(gVar.buffer[1]);
		newNode->next = NULL;
		newNode->prev = NULL;

		if (*Head)
		{
			newNode->next = *Head;
			(*Head)->prev = newNode;
		}
		*Head = newNode;
	}
	else
	{
		free(newNode);
		push_error(*Head, line_number);
	}
}
