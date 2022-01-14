#include "main.h"
/**
 * print_stack - print the stack from the top
 * @stack: the stack
 * @line_number: number of line
 * Return: void
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
