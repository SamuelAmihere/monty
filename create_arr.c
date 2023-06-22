#include "monty.h"

/**
* populate_inst_array - populates an array with instructions
*
* @all_inst: array of instructions
* @all_nums: array of numbers
* @stack_num: number to push
* @inst: instruction
* @i: index
* Return: nothing
*/
void populate_array(char *all_inst[MAX_INST], int *all_nums,
int stack_num, char *inst, int i)
{
	all_inst[i] = inst;
	if (strcmp(inst, "push") == 0)
		all_nums[i] = stack_num;
	else
		all_nums[i] = 0;
}


/**
* array_len_int - returns the length of an array
* @array: array
* Return: length of the array
*/
int array_len_int(int *array)
{
	int i;

	for (i = 0; array[i]; i++)
		;

	return (i);
}

/**
* array_len_str - returns the length of an array
* @array: array
* Return: length of the array
*/
int array_len_str(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		;

	return (i);
}
