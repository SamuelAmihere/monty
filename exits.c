#include "monty.h"

/**
 * exit_not_integer - exits with error message if not integer
 * frees everything
 * @line_number: line number
 * @line: line to free
 * @all_inst: array of instructions to free
 * @file: file to close
 * @all_nums: array of numbers to free
 * Return: nothing
 */
void exit_not_integer(int line_number, char *line,
		char **all_inst, FILE *file, int *all_nums)
{
	printf("L%d: usage: push integer\n", line_number);

	free_all(line, all_inst, all_nums);

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
