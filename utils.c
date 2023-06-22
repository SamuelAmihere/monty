#include "monty.h"

/**
 * arg_checker - checks for argument requirements
 *
 * @argc: number of arguments enetred into program
 *
 * Return: nothing
 */
void arg_checker(int argc)
{
	if (argc != 2)
		exit_arg_err();
}
