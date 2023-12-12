#include "monty.h"

/**
 * notDigit - check for digit
 *
 * @buf: the second argument to check if it is
 * digit or not (push 5   --> return 0)
 *              (push sfd --> return 1)
 *
 * Return: 0 for digit and 1 for alpha
 */
int notDigit(char *buf)
{
	size_t i = 0;

	if (!buf) /* If no argument passed to push */
		return (1);

	if (buf[0] == '-') /* for negative numbers */
		i++;

	for (; buf[i] != '\0'; i++)
		if (buf[i] < '0' || buf[i] > '9')
			return (1);

	return (0);
}
