#include "monty.h"

/**
* push_dnodeint - adds a new node at the end of a linked list
*
* @stack: starting node
* @line_number: Integer to be added.
*
* Return: Nothing
*/
void push_dnodeint(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		exit_malloc_err();

	new->n = line_number;
	new->next = *stack;

	if (*stack == NULL)
		new->prev = NULL;
	else
	{
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
	}

	*stack = new;
}

/**
* print_dlistint - prints  all the elements of a dlistint_t
*
* @stack: pointer to the head node of dlistint_t
* @line_number: line number
*
* Return: Nothing
*/
void print_dlistint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	if (*stack != NULL)
	{
		tmp = *stack;
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}

/**
 * print_dlistint_top - prints  node at the top of the stack
 * @stack: pointer to the head node of dlistint_t
 * @line_number: line number
 * Return: Nothing
 */
void print_dlistint_top(stack_t **stack, unsigned int line_number)
{

	if (!(*stack))
		exit_pint_err(line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop_dlistint_top - removes the top element of the stack
 * @stack: pointer to the head node of dlistint_t
 * @line_number: line number
 * Return: Nothing
 */
void pop_dlistint_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack))
		exit_pop_err(line_number);

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
* handle_instruction - handles the instruction
* @inst: instruction
* @num: number
* Return: 1 on success, 0 on failure
*/
int handle_instruction(char *inst, int num)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push_dnodeint},
		{"pall", print_dlistint},
		{"pint", print_dlistint_top},
		{"pop", pop_dlistint_top},
		{"swap", swap_top_two},
		{"add", add_top_two},
		{"nop", NULL},
		{"sub", sub_top_two},
		{NULL, NULL}};

	for (i = 0; i < 8; i++)
	{
		if (strcmp(opcodes[i].opcode, inst) == 0)
		{
			if (opcodes[i].f)
				opcodes[i].f(&head, num);

			return (1);
		}
	}

	return (0);
}
