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
	unsigned int node_number;
	int result, counter;
	(void)line_number;

	node = *stack;
	node_number = 0;
	for (counter = 0; node != NULL; counter++)
	{
		node_number++;
		node = node->next;
	}
	if (node_number < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		result = ((*stack)->next->n) + ((*stack)->n);
		(*stack)->next->n = result;
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
	}
}
