#include "monty.h"

/**
 * check_operation - check and go to operation
 * @operation: operation to chose from
 * @Stack: Stack to free it
 * @line: number of line in error
 */
void check_operation(instruction_t operation[], stack_t **Stack, size_t line)
{
	size_t j;

	for (j = 0; operation[j].opcode; j++)
	{
		if (strcmp(operation[j].opcode, gVar.buffer[0]) == 0)
		{
			operation[j].f(Stack, line);
			break;
		}
	}
	if (operation[j].opcode == NULL)
	{
		fprintf(stderr, "L%ld: unknown instruction %s\n", line, gVar.buffer[0]);
		fclose(gVar.fileName), free(gVar.instruction);
		freeStack(*Stack), exit(EXIT_FAILURE);
	}
}
