#include "monty.h"
/**
 *
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (!temp->next)
	{
		fprintf(stderr, "L%d: can't pop empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack  = *temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
