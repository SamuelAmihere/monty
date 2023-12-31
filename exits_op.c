#include "monty.h"

/**
 * exit_pint_err - exits if pint fails
 *
 * @line_number: line number
 *
 * Return: nothing
 */
void exit_pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_stack(head);
	exit(EXIT_FAILURE);
}

/**
 * exit_inst_err - exits if pop fails
 *
 * @line_number: line number
 * @inst: instruction
 * @file: file to close
 *
 * Return: nothing
 */
void exit_inst_err(unsigned int line_number, char *inst, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, inst);
	if (inst)
		free(inst);
	if (head)
		free_stack(head);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * exit_pop_err - exits if pop fails
 *
 * @line_number: line number
 *
 * Return: nothing
 */
void exit_pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_stack(head);
	exit(EXIT_FAILURE);
}

/**
 * exit_swap_err - exits if swap fails
 *
 * @line_number: line number
 *
 * Return: nothing
 */
void exit_swap_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_stack(head);
	exit(EXIT_FAILURE);
}

/**
 * exit_add_err - exits if add fails
 *
 * @line_number: line number
 *
 * Return: nothing
 */
void exit_add_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_stack(head);
	exit(EXIT_FAILURE);
}
