#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * bubble_sort - performs sorting of an integer array in ascending order
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 *
 * Description: uses bubble sort to sort the array.
 * Bubble involves the swapping of items subsequently until
 * all are sorted.
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	/* only continue bubbling when a swap occurs */
	bool swap_occurred;
	bool do_swap;
	size_t i;

	/* initialize swap_occurred to true for program to initialize the loop */
	swap_occurred = true;
	do_swap = false;
	while (swap_occurred)
	{
		swap_occurred = false;
		for (i = 0; i < size; i++)
		{
			do_swap = compare_pre_post_indexes(array, i, size);
			/* if compare return true it means a swap has to be done */
			if (do_swap)
			{
				swap(array, i, (i + 1), size);
				/* print array every time a swap occurs */
				print_array(array, size);
				swap_occurred = true;
			}

		}

	}
}

/**
 * compare_pre_post_indexes - prepares current index and the index
 * item that is next in array
 * @array: Array to be sorted
 * @current_index: current array index
 * @size: Size of array to be sorted
 *
 * Description: When the current index equals to end
 * index it just returns false
 * current_item is > next_item return true so that swap is performed
 * current_item is < next_item return false so that no swap is performed
 * current_item == last_array_item return false and don't access
 * the next item as it will be array out of bounds.
 * Return: true when post is less that pre else returns false
 */
bool compare_pre_post_indexes(int *array, size_t current_index, size_t size)
{
	int next_index;
	int current_array_item;
	int next_array_item;

	/* Checks to array bounds out of index bound is not raised */
	if (current_index == (size - 1))
		return (false);
	next_index = current_index + 1;

	/* save items to temporary buckets for ease of comparison */
	current_array_item = array[current_index];
	next_array_item = array[next_index];

	/*Perform Comparison for equality and if items are equal just retrn false */
	if (current_array_item == next_array_item)
		return (false);

	/* needs to be sorted thus return true so that swap can be done */
	if (current_array_item > next_array_item)
		return (true);
	/* already sorted thus do nothing */
	if (current_array_item < next_array_item)
		return (false);
	return (false);

}

/**
 * swap - is a modifier function that swaps values in specified indices
 * @array: array with item indexes to be swapped
 * @index_i: index to swap item
 * @index_j: index to swap item
 * @s: The size of input array
 *
 * Description: Swaps value items in the specified indices
 * Return: Void
 */
void swap(int *array, size_t index_i, size_t index_j, size_t s)
{
	int temp;
	/* checks that array is not null */
	/* checks that indexes are not the same and */
	if (!array)
	{
		/*perror("array can't be NULL");*/
		exit(EXIT_FAILURE);
	}
	if (index_i == index_j)
	{
		/*perror("Indexes can't be the same");*/
		exit(EXIT_FAILURE);
	}

	/* that they are valid.[not out of bounds indexes] */
	if (index_i > (s - 1) || index_j > (s - 1))
	{
		/*perror("Index can't be an out of bounds index");*/
		exit(EXIT_FAILURE);
	}
/* Performing a swap*/

	temp = array[index_i];
	array[index_i] = array[index_j];
	array[index_j] = temp;


}
