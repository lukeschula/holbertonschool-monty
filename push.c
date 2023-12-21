#include "monty.h"
/**
 *
 */
void _push(stack_t **stack, unsigned int line_num)
{
	int node_int;
	stack_t new_node = NULL;
	(void)line_num;

	new_node = atoi(nodeValue);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Erorr: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add_node->n = node_int;
	add-node->next = *stack;
	add_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
