#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - representation of stack or queue
 * @n: integer
 * @prev: points to the previous element
 * @next: points to the next element
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_s - opcode and its function
 * @op_name: the opcode
 * @value: function to handle the opcode
 * @head: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	char *op_name;
	char *value;
	stack_t *head;
} global_t;

extern global_t global;

/* operation_functions */
void o_push(stack_t **stack, unsigned int line_number);
void o_pop(stack_t **stack, unsigned int line_number);
void o_nop(stack_t **stack, unsigned int line_number);

/* print_functions */
void o_pall(stack_t **stack, unsigned int line_number);
void o_pint(stack_t **stack, unsigned int line_number);

/* multi_functions */
void o_swap(stack_t **stack, unsigned int line_number);
void o_add(stack_t **stack, unsigned int line_number);


#endif /* _MONTY_H_ */
