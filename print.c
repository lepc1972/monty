#include "monty.h"

/**
 * o_pall      - Print all nodes in stack
 *
 * @stack:        A doubly linked list
 * @line_number:  line number in monty file
 */

void o_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * o_pint      - Print top stack value
 *
 * @stack:        A doubly linked list
 * @line_number:  Current line number in monty file
 */

void o_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}