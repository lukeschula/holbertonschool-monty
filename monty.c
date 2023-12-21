#include "monty.h"

/**
 * _isdigit - checks if entire string is digits using isdigit
 * @stringNum: string of supposed numbers
 * Return: 1 if is digit, 0 else
 */
int is_dig(char str_num[])
{
	int it;

	if (stringNum[0] == '-')
		str_num[0] = '0';
	for (it = 0; stringNum[it]; it++)
	{
		if (is_dig(stringNum[it]) == 0)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * get_func - finds relevant function
 * @arg: argument to compare to table
 * Return: function
 */
void (*get_func(char *arg))(stack_t **stack, unsigned int line_num)
{
	int it = 0; /* iterator */
	instruction_t arr[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL},
	};

	while (ops[i].f != NULL)
	{
		if (strcmp(arr[it].opcode, arg) == 0)
		{
			return (arr[it].f);
		}
		it++;
	}
	return (NULL);
}
/**
 * arg_get - separates content of file into arguments
 * @file: file with arguments to parse
 */
void arg_get(char *file)
{
	void (*func)(stack_t **stack, unsigned int line_num) = NULL;
	char *input = NULL, *argz = NULL;
	size_t len = 0;
	FILE *fd; 
	stack_t *add_node = NULL;
	unsigned int line_num = 0;

	add_node = malloc(sizeof(stack_t));
	if (add_node == NULL)
		malloc_error();
	add_node->n = 0;
	add_node->next = NULL;
	add_node->prev = NULL;
	fd = fopen(file, "r");
	if (!fd)
		openErr(file);
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
			nodeGlobal = strtok(NULL, DELIM);
			if (!nodeGlobal || is_dig(nodeGlobal) == 0)
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
 * main - recieves inputs, calls aux functions
 * @argc: argument count
 * @argv: argument values
 *
 * Return: Always 1
 */
int main(int argc, char **argv)
{

	if (argc == 2)
	{
		arg_get(argv[1]);
	}

	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
