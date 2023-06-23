#include "monty.h"

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
