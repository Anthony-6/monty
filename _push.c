#include "monty.h"
/**
 * add_node - main function
 * add_node:  add new node to the list
 * @stack: pointer
 * @newnode - create a newnode to add
 * @line_number: main value
 * Return: number of element or NULL if it fails
 */
void add_node(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}	
	newnode->n = line_number;
	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}
