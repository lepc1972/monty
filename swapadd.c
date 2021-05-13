#include "monty.h"

/**
 * o_swap      - Swaps top two elements of stack
 *
 * @stack:        A doubly linked list
 * @line_number:  line number in monty file
 */

void o_swap(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = (*stack)->n - (*stack)->next->n;
	(*stack)->n = (*stack)->n - (*stack)->next->n;
}

/**
 * o_add       - Adds the top two elements of @stack
 *
 * @stack:        A doubly linked list
 * @line_number:  line number in monty file
 */

void o_add(stack_t **stack, unsigned int line_number)
{
	stack_t *target;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	target = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;

	free(target);



}
