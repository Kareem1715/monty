#include "monty.h"

char *buffer[] = {NULL};

/*void freeStack(stack_t *Head)
{
	stack_t *nxt;

	while (Head)
	{
		nxt = Head->next;
		free(Head);
		Head = nxt;
	}
}
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
void pallFunc(stack_t **Head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *trv = *Head;

	while (trv)
	{
		printf("%d\n", trv->n);
		trv = trv->next;
	}
}
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
*/
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
