#include "monty.h"
/**
 * _pint - prints the value at the top of the stack
 * @stack: The stack
 * @line_number: number of line
 * Return: Nothing.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
