#include "monty.h"
/**
 *
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *top = *stack;

	if (!top->next)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", read->n);
}
