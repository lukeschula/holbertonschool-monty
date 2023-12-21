#include "monty.h"
/**
 *
 *
 *
 */
void push_func(stack_t **top, unsigned int line_num)
{
	stack_t *add_node;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}
	add_node = malloc(sizeof(stack_t));
	if (add_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add_node->next = *top;
	add_node->prev = NULL;
	add_node->n = global_num;
	if (*top)
		(*top)->prev = add_node;
	*top = add_node;
}
/**
 *
 */
void pall_func(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	(void) line_num;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 *
 */
void pint_stack(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", temp->n);
}
/**
 *
 */
void free_stack(stack_t **top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	temp = *top;
	while (temp)
	{
		*top = temp->next;
		free(temp);
		temp = *top;
	}
}
