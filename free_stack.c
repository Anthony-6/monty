
#include "monty.h"

/**
 * free_stack - function that free a stack
 * @stack: the stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *memory_free;

	while (*stack != NULL)
	{
		memory_free = *stack;
		*stack = (*stack)->next;
		free(memory_free);
	}
}
