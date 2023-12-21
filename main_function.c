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
