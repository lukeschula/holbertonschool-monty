#include "monty.h"
/**
 *
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int x;
	
	temp = *stack;
	if (!temp->next || !temp->next->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	x = temp->n;
	temp->n = temp->next->n;
	temp->next->n = x;
}	
