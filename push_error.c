#include "monty.h"


/**
 * push_error - close file, free and exit
 *
 * @Head: list to free it
 * @newNode: newNode varibale to free it.
 *
 * Return: Nothing
 */
void push_error(stack_t *Head, stack_t *newNode)
{
	freeStack(Head);
	free(newNode);
	free(gVar.instruction);
	fclose(gVar.fileName);
	exit(EXIT_FAILURE);
}
