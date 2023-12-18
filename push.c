#include "monty.h"
/**
 *
 *
 *
 *
 */
void push( char *special_token, unsigned int num)
{
	int n;
	
	if (strcmp(special_token, "push") == 0)
	{
		special_token = strtok(NULL, " \t\n");

		if (special_token == NULL)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", num);
			
			free_all();
			exit(EXIT_FAILURE);
		}	
