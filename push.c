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
	size_t i = 0;
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (gVar.buffer[1])
	{
		if (gVar.buffer[1][0] == '-')
			i++;
		for (; gVar.buffer[1][i] != '\0'; i++)
		{
			if (gVar.buffer[1][i] < '0' || gVar.buffer[1][i] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(gVar.buffer[0]);
				push_error(*Head, newNode);
			}
		}
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
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		push_error(*Head, newNode);
	}
}
