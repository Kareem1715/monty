#include "monty.h"
/**
 * pushFunc - add node to the stack
 * @Head: stack head
 * @line_number: line_number error
 * Return: no return
*/
void pushFunc(stack_t **Head, unsigned int line_number)
{
	size_t i = 0;
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (buffer[1])
	{
		if (buffer[1][0] == '-')
			i++;
		for (; buffer[1][i] != '\0'; i++)
		{
			if (buffer[1][i] < '0' || buffer[1][i] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(newNode);
				freeStack(*Head);
				free(buffer[0]);
				exit(EXIT_FAILURE);
			}
		}

		newNode->n = atoi(buffer[1]);
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
		free(newNode);
		freeStack(*Head);
		free(buffer[0]);
		exit(EXIT_FAILURE);
	}
}


/**
 * pallFunc - prints the stack
 * @Head: stack head
 * @line_number: line number error
 * Return: no return
*/
void pallFunc(stack_t **Head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *trv = *Head;

	while (trv)
	{
		printf("%d\n", trv->n);
		trv = trv->next;
	}
}


/**
 * pintFunc - prints the top
 * @Head: stack head
 * @line_number: line_number error
 * Return: no return
*/
void pintFunc(stack_t **Head, unsigned int line_number)
{
	stack_t *trv = *Head;

	if (!*Head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (trv)
		printf("%d\n", trv->n);
}
