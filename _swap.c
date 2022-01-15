
#include "monty.h"

/**
 * _swap - function that swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number for error
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	unsigned int i = 0;
	int counter;
	int node_1;
	int node_2;

	for (counter = 0; node != NULL; counter++)
	{
		i++;
		node = node->next;
	}

	if (i <= 1)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		node_1 = (*stack)->n;
		node_2 = (*stack)->next->n;
		(*stack)->n = node_1;
		(*stack)->next->n = node_2;
	}
}
