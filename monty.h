#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


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

/**
 * struct globalVaribale_s - global varibales
 *
 * @buffer: Buffer that has a monty and value linke `push 5`
 * @instruction: The line taken by getline
 * @fileName: Use it to close file before exit
 *
 * Description: This struct use to access for
 * buffer, instruction and fileName in any file.
 */
typedef struct globalVaribale_s
{
	char *buffer[2];
	char *instruction;
	FILE *fileName;
} glob_t;

extern glob_t gVar;

void pushFnc(stack_t **Head, unsigned int line_number);
void pallFnc(stack_t **Head, unsigned int line_number);
void pintFnc(stack_t **Head, unsigned int line_number);
void popFnc(stack_t **Head, unsigned int line_number);
void swapFnc(stack_t **Head, unsigned int line_number);
void addFnc(stack_t **Head, unsigned int line_number);
void nopFnc(stack_t **Head, unsigned int line_number);
void subFnc(stack_t **head, unsigned int line_number);
void divFnc(stack_t **head, unsigned int line_number);
void mulFnc(stack_t **Head, unsigned int line_number);
void modFnc(stack_t **Head, unsigned int line_number);
void pcharFnc(stack_t **Head, unsigned int line_number);
void pstrFnc(stack_t **Head, unsigned int line_number);

void check_operation(instruction_t operation[], stack_t **Stack, size_t lineNum);
int check_empty_line(size_t lineNum, char *instruction);
void push_error(stack_t *Head, stack_t *newNode);
void freeStack(stack_t *Head);

#endif
