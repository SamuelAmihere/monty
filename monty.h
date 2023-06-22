#ifndef MONTY_H
#define MONTY_H

/* ============== LIBRARIES ======= */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* ============== MACROS ==========*/
#define MAX_INST 1024

/* ============== STRUCTS =========*/

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

/* ============= GLOBALS ============= */
extern stack_t *head;

/* ============= PROTOYPES =========== */
/* in_out.c */
void add_dnodeint(stack_t **stack,
	unsigned int line_number);
void print_dlistint(stack_t **stack, unsigned int line_number);
void print_dlistintend(stack_t **stack, unsigned int line_number);
void handle_instruction(char *inst, int num);

/* monty.c*/
char *parser(char *line, int *line_number, int *num_ptr);
int is_number(char *s);
int stack_len(stack_t **stack);
FILE *open_file(char *file);

/* create_arr.c */
void populate_array(char *all_inst[MAX_INST], int *all_nums,
int stack_num, char *inst, int i);
int array_len_str(char **array);
int array_len_int(int *array);

/* frees.c */
void free_stack(stack_t *stack);
void free_arrays_str(char *array[]);
void free_arrays_int(int **array);


#endif
