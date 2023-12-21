#include "monty.h"
/**
 *
 */
void free_list(stack_t *head)
{
	if (head->next)
	{
		free_list(head->next);
	}
	free(head);
}
/**
 *
 *
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 *
 */
void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 *
 */
void func_error(unsigned int l_n, stack_t *h, char *input, char *opc, FILE *fd)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", l_n, opc);
	free_list(h);
	free(input);
	fclose(fd);
	exit(EXIT_FAILURE);
}
/**
 *
 */
void push_error(unsigned int line_num, stack_t *head, char *input, FILE fd)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	free_list(head);
	free(input);
	fclose(fd);
	exit(EXIT_FAILURE);
}
