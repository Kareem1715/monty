#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

extern char *buffer[];
extern FILE *fileName;
extern char *instruction;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;




/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void freeStack(stack_t *Head);
void pushFunc(stack_t **Head, unsigned int line_number);
void pallFunc(stack_t **Head, __attribute__((unused)) unsigned int line_number);
void pintFunc(stack_t **Head, unsigned int line_number);
void popFunc(stack_t **Head, unsigned int line_number);
void swapFunc(stack_t **Head, unsigned int line_number);
void addFunc(stack_t **Head, unsigned int line_number);
void nopFunc(__attribute__((unused)) stack_t **Head, __attribute__((unused)) unsigned int line_number);

#endif /* MONTY_H */
