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
		return (-1);
	}
	if (str[0] == '-')
		i = 1;
	for (; str[i] != 0; i++)
	{
		if (isdigit(str[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
	}
	return (1);
}
