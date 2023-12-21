#include "monty.h"
/**
 *
 */
int is_dig(char *token)
{
	int it;

	if (token == NULL)
		return (-1);
	for (it = 0; token[it] != '\0'; it++)
	{
		if (!(token[it] >= '0' && token[it] <= '9') && token[it] != '-')
			return (-1);
	}
	return (0);
}
/**
 *
 */
int open_file(char *file, stack_t **stack)
{
	FILE *contents;
	char *token = NULL, *buff_line = NULL, *num = NULL;
	unsigned int line_countr = 0;
	size_t buff_size;

	contents = fopen(file, "r");
	if (contents == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff_line, &buff_size, contents) != EOF)
	{
		token = strtok(buff_line, "\n\t\r ");
		num = strtok(NULL, "\n\t\r ");
		line_countr++;
		if (token && token[0] != '#')
		{
			if (strcmp(token, "push") == 0)
			{
				if (is_dig(num) == -1)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_countr);
					free_file(buff_line, contents);
				}
				global_num = atoi(num);
			}
			if (get_func(token, line_countr, stack) == 1)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_countr, token);
				free_file(buff_line, contents);
				free_stack(stack);
			}
		}
	}
	free(buff_line);
	free_stack(stack);
	fclose(contents);
	return (0);
}
/**
 *
 */
void free_file(char *buff_line, FILE *contents)
{
	free(buff_line);
	fclose(contents);
	exit(EXIT_FAILURE);
}
