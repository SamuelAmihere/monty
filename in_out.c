#include "monty.h"

/**
* add_dnodeint - adds a new node at the end of a linked list
*
* @stack: starting node
* @line_number: Integer to be added.
*
* Return: Nothing
*/
void add_dnodeint(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	new->n = line_number;

	if (!(*stack))
	{
		new->prev = NULL;
		new->next = NULL;
	} else
	{
		new->prev = (*stack)->prev;
		new->next = *stack;
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
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
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
	stack_t *tmp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}


/**
* handle_instruction - handles the instruction
* @inst: instruction
* @num: number
* Return: nothing
*/
void handle_instruction(char *inst, int num)
{
	int i;
	instruction_t opcodes[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
		{"pint", print_dlistint_top},
		{NULL, NULL}};

	for (i = 0; i < 3; i++)
	{
		if (strcmp(opcodes[i].opcode, inst) == 0)
			opcodes[i].f(&head, num);
	}
}
