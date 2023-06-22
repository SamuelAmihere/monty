#include "monty.h"

/**
* free_stack - frees a stack
* @stack: pointer to the head of the stack
* Return: nothing
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	if (stack)
	{
		while (stack)
		{
			tmp = stack;
			stack = stack->next;

			free(tmp);
		}
	}
	free(stack);
}


/**
* free_arrays_str - frees an array of strings
* @array: array of strings
* Return: nothing
*/
void free_arrays_str(char *array[])
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);

}

/**
* free_arrays_int - frees an array of ints
* @array: array of ints
* Return: nothing
*/
void free_arrays_int(int **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);

	free(array);
}
