#include "monty.h"
/**
 *
 *
 */
void pall(stack_t **stack, unsigned int num)
{
	(void) num;
	stack_t *fully_stacked;

	if (*stack == NULL)
		return;
	fully_stacked = *stack;

	while(fully_stacked != NULL)
	{
		printf("%d\n", fully_stacked->i)
		fully_stacked = fully_stacked->next;
	}
}
