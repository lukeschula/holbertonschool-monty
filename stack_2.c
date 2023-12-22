#include "monty.h"
/**
 * pop_func - delete the value at top of stack
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void pop_func(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	free(*top);
	*top = temp;
}
/**
 * swap_func - pushes an element to the stack
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void swap_func(stack_t **top, unsigned int line_num)
{
	stack_t *N_1_swap, *N_2_swap;

	N_1_swap = *top;
	if (*top && (*top)->next)
	{
		N_2_swap = N_1_swap->next; 
		N_1_swap->prev = N_1_swap->next;
		N_1_swap->next = N_2_swap->next;
		if (N_2_swap->next) 
			(N_2_swap->next)->prev = N_1_swap;
		N_2_swap->prev = NULL;
		N_2_swap->next = N_1_swap;
		*top = N_2_swap;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
}
/**
 * _add - dds the top two elements of the stack
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void _add(stack_t **top, unsigned int line_num)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n += (*top)->n;
	pop_func(top, line_num);
}
/**
 * _nop - function that does nop(ing)
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void _nop(stack_t **top, unsigned int line_num)
{
	(void) top;
	(void) line_num;
}
