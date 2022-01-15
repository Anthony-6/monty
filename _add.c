#include "monty.h"

/**
 * _add - function that add the two top element of a stack
 * @stack: the stack
 * @line_number: number of the line
 * Return: the result or an error message
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *node;
	unsigned int nodes;
	int i, counter;
	(void)line_number;

	node = *stack;
	nodes = 0;
	for (counter = 0; node != NULL; counter++)
	{
		nodes++;
		node = node->next;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = ((*stack)->next->n) + ((*stack)->n);
		(*stack)->next->n = i;
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
	}
}
