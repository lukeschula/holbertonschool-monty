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
