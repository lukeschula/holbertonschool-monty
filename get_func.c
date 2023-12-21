#include "monty.h"
/**
 *
 */
int get_func(char *token, unsigned int input, stack_t **stack)
{
	instruction_t operation[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	int it;

	for (it = 0; operation[it].opcode; it++)
	{
		if (strcmp(token, operation[it].opcode) == 0)
		{
			operation[it].f(stack, input);
			return (0);
		}
	}
	return (1);
}
