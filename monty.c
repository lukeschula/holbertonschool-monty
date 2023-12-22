#include "monty.h"
/**
 * main - entry point
 * @argc: Total of arguments
 * @argv: Arguments, monty file
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1], &stack);
	return (0);
}
