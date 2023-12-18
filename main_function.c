#include "monty.h"

/*
 *
 *
 *
 *
 */
int main( int argc, char *argv[])
{
	stack_t *stacks;
	char *input;
	char *special_token;
	unsigned int counter;
	unsigned int x;
	size_t length;

	buf.stacks = stacks;

	if (argc != 2)
		err_msg("USAGE ERROR: monty ", "file", EXIT_FAILURE);

