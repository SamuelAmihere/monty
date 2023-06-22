#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

/* Initialize globals*/
stack_t *head = NULL;

/**
* main - Entry point
*
* @argc: number of arguments
* @argv: array of arguments
*
* Return: 0 on Success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *inst, *all_inst[MAX_INST], *line = NULL;
	size_t len = 0;
	int *line_number, *stack_num_ptr, *all_nums,
	    stack_num = 0, ln = 0, i = 0;

	line_number = &ln;
	stack_num_ptr = &stack_num;
	arg_checker(argc);
	file = open_file(argv[1]);
	all_nums = malloc(sizeof(int) * MAX_INST);
	if (all_nums == NULL)
		exit_close_file(file);
	while (getline(&line, &len, file) != -1)
	{
		*line_number += 1;
		inst = parser(line, stack_num_ptr);
		if (inst == NULL)
			exit_not_integer(ln, line, file);

		handle_instruction(inst, stack_num);
		len = 0;
		i++;
	}

	free_all(line, all_inst, all_nums);
	fclose(file);
	return (0);
}

/**
 * parser - parses a line from a file
 * @line: line to parse
 * @num_ptr: pointer to number
 * Return: 0 on success, 1 on failure
 */
char *parser(char *line, int *num_ptr)
{
	char *token, *opcode, *arg;

	token = strtok(line, " \n\t"); /* Get first token */
	opcode = token;
	if (opcode == NULL)
		return (opcode);
	if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "pint") == 0)
		return (opcode);
	token = strtok(NULL, " \n\t"); /* Get second token */
	arg = token;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL || is_number(arg) == 0)
			return (NULL);
	}
	*num_ptr = atoi(arg);
	return (opcode);
}

/**
* is_number - checks if a string is a number
* @str: string to check
*
* Return: 1 if true, 0 if false
*/
int is_number(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			return (0);
	}

	return (1);
}

/**
* stack_len - returns the length of a stack
* @stack: pointer to the head of the stack
* Return: length of the stack
*/
int stack_len(stack_t **stack)
{
	stack_t *tmp;
	int len = 0;

	tmp = *stack;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	return (len);
}

/**
* open_file - opens a file
* @file: file to open
* Return: 0 on success, 1 on failure
*/
FILE *open_file(char *file)
{
	FILE *fp;

	fp = fopen(file, "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	return (fp);
}
