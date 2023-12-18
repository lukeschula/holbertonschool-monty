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
	
	buf.fd = fopen(arg[1], "r");

	if (buf.fd == NULL)
		err_msg("Error: File cannot open ", argv[1], EXIT_FAILURE);

	counter = linecount(buf.fd);
	buf.fd = fopen(argv[1] "r");

