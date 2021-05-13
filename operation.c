#include "monty.h"

/**
* o_push    - Push element on top of stack
*
* @stack:       doubly linked list
* @line_number: Current line number in monty file
*/

void o_push(stack_t **stack, unsigned int line_number)
{
stack_t *new;
unsigned int size;
int number;

if (global.value == NULL)
{
printf("L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
size = atoi(global.value) <= 0 ? 1 : 0;
number = abs(atoi(global.value));
while (number > 0)
{
number /= 10;
size++;
}
if (size != strlen(global.value))
{
printf("L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
new = malloc(sizeof(stack_t));
if (new == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new->n = atoi(global.value);
new->prev = NULL;
new->next = *stack;
if (*stack != NULL)
{
(*stack)->prev = new;
}
*stack = new;
global.head = new;
}

/**
* o_pop       - delete the top element of @stack
*
* @stack:        A doubly linked list
* @line_number:  Current line number in monty  file
*/

void o_pop(stack_t **stack, unsigned int line_number)
{
stack_t *target;

if (stack == NULL || *stack == NULL)
{
printf("L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

target = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
free(target);
{
(*stack)->prev = NULL;
}


}

/**
* o_nop       -  nothing
*
* @stack:        A doubly linked list
* @line_number:  Current line number  monty  file
*/

void o_nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
