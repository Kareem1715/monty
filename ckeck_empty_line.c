#include "monty.h"

/**
 * check_empty_line - check line
 *
 * @lineNum: number of line in error
 * @instruction: Use to free it.
 *
 * Return: 1 in success and 0 in fail
 */
int check_empty_line(size_t lineNum, char *instruction)
{
	if (gVar.buffer[0] == NULL)
	{
		lineNum++;
		free(instruction);
		return (1);
	}
	return (0);
}
