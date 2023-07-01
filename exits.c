#include "monty.h"

/**
 * exit_not_integer - exits with error message if not integer
 * frees everything
 * @line_number: line number
 * @line: line to free
 * @file: file to close
 * @inst: instruction to free
 * Return: nothing
 */
void exit_not_integer(int line_number, char *line, FILE *file)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);

	free(line);
	free_stack(head);
	exit_close_file(file);
}

/**
 * exit_close_file - closes file and exit program
 * @file: file to close
 * Return: nothing
 */
void exit_close_file(FILE *file)
{
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * exit_arg_err - exits if argument numnbers not satified
 *
 * Return: nothing
 */
void exit_arg_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * exit_malloc_err - exits if malloc fails
 *
 * Return: nothing
 */
void exit_malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
