#ifndef MONTY_H
#define MONTY_H

#define DELIM " \t\n\a\r"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fctnl.h>
#include <stddef.h>
#include <ctype.h>

char *nodeValue;

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

int is_dig(char str_num[]);
void (*sep_func(char *arg))(stack_t **stack, unsigned int line_num);
void sep_arg(char *file);
int main(int argc, char **argv);
void _swap(stack_t **stack, unsigned int line_num);
void _push(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void free_list(stack_t *head);
void malloc_error(void);
void open_error(char *file);
void func_error(unsigned int l_n, stack_t *h, char *input, char *opc, FILE *fd);
void push_error(unsigned int line_num, stack_t *head, char *input, FILE fd);
