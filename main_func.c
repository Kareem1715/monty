#include "monty.h"

char *buffer[] = {NULL};

void freeStack(stack_t *Head)
{
	stack_t *nxt;

	while (Head)
	{
		nxt = Head->next;
		free(Head);
		Head = nxt;
	}
}

int main(int argc, char **argv)
{
	FILE *fileName;
	char *instruction = NULL;
	size_t len = 0, lineNum = 1, i = 0, j;
	ssize_t readByt;
	stack_t *Stack = NULL;
	instruction_t operation[] = {
		{"push", pushFunc}, {"pall", pallFunc},
		{"pint", pintFunc}, {"pop", popFunc},
		{"swap", swapFunc}, {"add", addFunc},
	    {"nop", nopFunc},   {NULL, NULL}
	};

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fileName = fopen(argv[1], "r");
	if (fileName == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while ('T')
	{
		readByt = getline(&instruction, &len, fileName);
		if (readByt == EOF)
			break;
		i = 0, buffer[i] = strtok(instruction, " \n");
		if (buffer[0] == NULL)
		{
			lineNum++;
			continue;
		}
		while (buffer[i])
			buffer[++i] = strtok(NULL, " \n");
		for (j = 0; operation[j].opcode; j++)
		{
			if (strcmp(operation[j].opcode, buffer[0]) == 0)
			{

				operation[j].f(&Stack, lineNum);
				break;
			}

		}
		if (operation[j].opcode == NULL)
		{
			fprintf(stderr, "L%ld: unknown instruction %s\n", lineNum, buffer[0]);
			fclose(fileName);
			free(instruction);
			freeStack(Stack);
			exit(EXIT_FAILURE);
		}
		lineNum++;
	}
	fclose(fileName);
	free(instruction);
	freeStack(Stack);
	return (0);
}
