#include "monty.h"
/**
 *
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;
	(void) line_num;

	while (ptr->next)
	{
		printf("%i\n", ptr->n);
		ptr = ptr->next;
	}
}
