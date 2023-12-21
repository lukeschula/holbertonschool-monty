#include "monty.h"
/**
 *
 */
void _add(stack_t **stack, unsigned intine_num)
{
	stack_t *temp;
	int s;

	temp = *stack;
	if (!(*stack)->next || !(*stack)->next->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	s = temp->next->n + temp->n;
	temp = temp->next;
	_pop(stack, line_num);
	temp->n = s;
}
