#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort-Sorts an array using Selection Sorting
 * @array: Input array to be sorted
 * @size: Size of the array
 * Description:
 * selection involves scanning through the
 * entire list and choosing the smallest
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, position, swap;

	/* handle case when array pointer is invalid*/
	if (!array || size <= 0)
		exit(EXIT_FAILURE);
	for (i = 0; i < (size - 1); i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[position] > array[j])
				position = j;
		}
		if (position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
		}
		print_array(array, size);
	}
}
