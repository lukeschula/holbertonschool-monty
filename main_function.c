#include "monty.h"
/**
 *
 */
int is_dig(char str_num[])
{
	int it;

	if (str_num[0] == '-')
		str_num[0] = '0';
	for (it = 0; str_num[it]; it++)
	{
		if (isdigit(str_num[it]) == 0)
		{
			return (0);
		}
	}
	return (1);
}
/**
 *
 */
void (*sep_func(char *arg))(stack_t **stack, unsigned int line_num)
{
	int it = 0;

	instruction_t arr[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	while (arr[it].f != NULL)
	{
		if (strcmp(arr[it].opcode, arg) == 0)
		{
			return (arr[it].f);
		}
		it++;
	}
}
/**
 *
 */

