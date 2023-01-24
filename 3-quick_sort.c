#include<stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quicksort- performs sorting
 * @number: array to be sorted
 * @first: first array element
 * @last: last array element
 * @size: size of array
 *
 * Return: void
 */

void quicksort(int *number, int first, int last, size_t size)
{
	int i, j, pivot, temp;


	print_array(number, size);
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, first, j - 1, size);
		quicksort(number, j + 1, last, size);
	}
}

/**
 * quick_sort - helper function for quicksort
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, (size - 1), size);
}
