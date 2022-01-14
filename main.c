#include "monty.h"
/**
 * main - file interpretor for monty bytecode files
 * @argc: number of argument needed
 * @argv: argument
 * Return: always success
 */
int main(int argc, char **argv)
{
	FILE *file_to_open;
	ssize_t line_read;
	char *line = NULL;
	size_t buffer = 0;
	stack_t *list = NULL;
	int line_number = 1, i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_to_open = fopen(argv[1], "r");
	if (file_to_open == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_read = getline(&line, &buffer, file_to_open)) != -1)
	{
		i = check_tok(&list, line, line_number);
		if (i == -1)
		{
			line_number++;
			continue;
		}
		if (i == 0)
			break;
		line_number++;
	}
	free(line);
	fclose(file_to_open);
	if (i == 0)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}
