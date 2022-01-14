#include "main.h"
#include <stdio.h>
/**
 * check_tok - function to tokenize the line given by the file
 * and to check if a token matches with argument inside the
 * op_code struct
 * @stack: the structur stack
 * @line: line inside the file
 * @line_number: number of line
 * Return: -1, 0 or 1
 */
int check_tok(stack_t **stack, char *line, int line_number)
{
	instruction_t op_code[] = {{"push", add_node},
				   {"pall", print_stack},
				   {NULL, NULL}};
	int i = 0;
	char *token_op_code, *token_value;

	token_op_code = strtok(line, " \n");
	if (token_op_code == NULL)
	{
		line_number++;
		return (-1);
	}
	for (i = 0; op_code[i].opcode; i++)
		if (strcmp(token_op_code, op_code[i].opcode) == 0)
		{
			token_value = strtok(NULL, " \n");
			if (i == 0)
			{
				if (isint(token_value, line_number) == -1)
					return (0);
				op_code[i].f(stack, atoi(token_value));
			}
			else
				op_code[i].f(stack, line_number);
			return (1);
		}
	fprintf(stderr, "L%d: unknow instruction %s\n", line_number, token_op_code);
	return (0);
}
