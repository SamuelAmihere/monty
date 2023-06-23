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
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	int *line_number, *stack_num_ptr, stack_num = 0,
		ln = 0, i = 0, op_status = 0;

	line_number = &ln;
	stack_num_ptr = &stack_num;
	arg_checker(argc);
	file = open_file(argv[1]);

	while (getline(&line, &len, file) != -1)
	{
		*line_number += 1;
		opcode = strtok(line, " \n\t"); /* Get first token */
		if (opcode == NULL || opcode[0] == '#')
			continue;

		parser(opcode, stack_num_ptr);

		if (stack_num == -1)
			exit_not_integer(ln, line, file, opcode);

		op_status = handle_instruction(opcode, stack_num);

		if (op_status == 0)
			exit_inst_err(ln, opcode, file);

		free(opcode);

		len = 0;
		i++;

	}

	free(line);
	free_stack(head);
	fclose(file);
	return (0);
}

/**
 * parser - parses a line from a file
 * @opcode: opcode
 * @num_ptr: pointer to number
 * Return: 0 on success, 1 on failure
 */
void parser(char *opcode, int *num_ptr)
{
	char *token, *arg;

	token = strtok(NULL, " \n\t"); /* Get second token */
	arg = token;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL || is_number(arg) == 0)
		{
			*num_ptr = -1;
			return;
		}
		*num_ptr = atoi(arg);
	}
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
