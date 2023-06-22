#include "monty.h"

/**
 * exit_not_integer - exits with error message if not integer
 * frees everything
 * @line_number: line number
 * @line: line to free
 * @file: file to close
 * Return: nothing
 */
void exit_not_integer(int line_number, char *line, FILE *file)
{
	printf("L%d: usage: push integer\n", line_number);

	free(line);

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
