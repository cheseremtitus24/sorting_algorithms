#ifndef __SORT__
#define __SORT__

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void bubble_sort(int *array, size_t size);

void print_array(const int *array, size_t size);

void swap(int *array, size_t index_i, size_t index_j, size_t s);

bool compare_pre_post_indexes(int *array, size_t current_index, size_t size);

void selection_sort(int *array, size_t size);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);

#endif
