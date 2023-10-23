#include "monty.h"

glob_t gVar = {{NULL, NULL}, NULL, NULL};

/**
 * main - main function
 *
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 (always success)
 */
int main(int argc, char **argv)
{
	stack_t *Stack = NULL;
	size_t len = 0, lineNum = 1, i = 0;
	ssize_t readByt;
	char *instruction = NULL;

	instruction_t operation[] = {
		{"push", pushFnc}, {"pall", pallFnc}, {"pint", pintFnc}, {"pop", popFnc},
		{"swap", swapFnc}, {"add", addFnc}, {"nop", nopFnc}, {"sub", subFnc},
		{"div", divFnc},   {"mul", mulFnc}, {"mod", modFnc}, {"pchar", pcharFnc},
		{"pstr", pstrFnc}, {NULL, NULL}
	};

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	gVar.fileName = fopen(argv[1], "r");
	if (gVar.fileName == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while ('T')
	{
		instruction = NULL;
		readByt = getline(&instruction, &len, gVar.fileName);
		gVar.instruction = instruction;
		if (readByt == EOF)
			break;

		i = 0, gVar.buffer[i] = strtok(gVar.instruction, " \n");
		if (check_empty_line(lineNum, instruction))
			continue;

		while (gVar.buffer[i])
			gVar.buffer[++i] = strtok(NULL, " \n");

		check_operation(operation, &Stack, lineNum);

		lineNum++, free(instruction);
	}
	fclose(gVar.fileName), free(gVar.instruction), freeStack(Stack);

	return (0);
}
