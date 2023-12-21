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
void sep_arg(char *file)
{
	void (*func)(stack_t **stack, unsigned int line_num) = NULL;
	char *input = NULL;
	char *argz = NULL;
	unsigned int line_num = 0;
	size_t len = 0;
	FILE fd;
	stack_t *add_node = NULL;

	add_node = malloc(sizeof(stack_t));
	if (add_node == NULL)
		malloc_error();
	add_node->n = 0;
	add_node->next = NULL;
	add_node->prev = NULL;
	fd = fopen(file, "r");
	if (!fd)
		open_error(file);
	while (getline(&input, &len, fd) != -1)
	{
		line_num++;
		argz = strtok(input, DELIM);
		if (!argz)
			continue;
		func = get_func(argz);
		if (func == NULL)
			func_error(line_num, add_node, input, argz, fd);
		if (func == _push)
		{
			nodeValue = strtok(NULL, DELIM);
			if (!nodeValue || is_dig(nodeValue) == 0)
				push_error(line_num, add_node, input, fd);
		}
		func(&add_node, line_num);
	}
	fclose(fd);
	free(input);
	free_list(add_node);
	exit(EXIT_SUCCESS);
}
/**
 *
 */
int 
