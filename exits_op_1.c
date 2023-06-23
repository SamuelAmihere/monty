#include "monty.h"

/**
 * exit_malloc_err - exits with error message
 * Return: nothing
 */
void exit_sub_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_stack(head);
	exit(EXIT_FAILURE);
}
