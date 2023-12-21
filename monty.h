#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int global_num;

int is_dig(char *token);
int open_file(char *file, stack_t **stack);
void free_file(char *buff_line, FILE *contents);
int main(int argc, char *argv[]);
int get_func(char *token, unsigned int input, stack_t **stack);
void free_stack(stack_t **top);
void pint_stack(stack_t **top, unsigned int line_num);
void push_func(stack_t **top, unsigned int line_num);
void pall_func(stack_t **top, unsigned int line_num);
void pop_func(stack_t **top, unsigned int line_num);
void swap_func(stack_t **top, unsigned int line_num);
void _add(stack_t **top, unsigned int line_num);
void _nop(stack_t **top, unsigned int line_num);
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t print_dlistint(const stack_t *h);

#endif
