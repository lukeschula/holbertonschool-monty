#include "monty.h"
/**
 * push_func - pushes an element to the stack
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void push_func(stack_t **top, unsigned int line_num)
{
	stack_t *add_node;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}
	add_node = malloc(sizeof(stack_t));
	if (add_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add_node->next = *top;
	add_node->prev = NULL;
	add_node->n = global_num;
	if (*top)
		(*top)->prev = add_node;
	*top = add_node;
}
/**
 * pall_func - Prints all values of stack
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void pall_func(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	(void) line_num;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_func - that print the valueat top of stack
 * @top: element at the top of the stack
 * @line_num: constant int value in the structure
 */
void pint_func(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", temp->n);
}
/**
 * free_stack - print the valueat top of stack
 * @top: element at the top of the stack
 */
void free_stack(stack_t **top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	temp = *top;
	while (temp)
	{
		*top = temp->next;
		free(temp);
		temp = *top;
	}
}
