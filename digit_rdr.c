#include "monty.h"
/**
 *
 *
 *
 */
int digit_rdr(char *special_token)
{
	int x = 0;
	
	while (special_token[x])
	{
		if (special_token[0] == '-')
		{
			++x;
			continue;
		}
		
		if (special_token[x] < '0' || special_token[x] > '9')
			return (0);
		
		++x

	}
	
	return (1);
}	
