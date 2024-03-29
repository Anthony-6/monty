#include "monty.h"
/**
 * isint - check in the line if a character is a integer or not
 * @str: pointer to the string
 * @line_number: number of line
 * Return: always success
 */
int isint(char *str, int line_number)
{
	int i = 0;

	if (str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (str[0] == '-')
		i = 1;
	for (; str[i]; i++)
	{
		if (isdigit(str[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
