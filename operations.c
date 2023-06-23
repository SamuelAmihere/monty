#include "monty.h"

/**
 * swap_top_two - swaps the top two elements of the stack
 * @stack: pointer to the head node of dlistint_t
 * @line_number: line number
 * Return: Nothing
 */
void swap_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (stack_len(stack) < 2)
		exit_swap_err(line_number);

	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}

/**
 * add_top_two - adds the top two elements of the stack
 * @stack: pointer to the head node of dlistint_t
 * @line_number: line number
 * Return: Nothing
 */
void add_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (stack_len(stack) < 2)
		exit_add_err(line_number);

	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp->next->n + tmp_n;

	swap_top_two(stack, line_number);
	pop_dlistint_top(stack, line_number);
}
