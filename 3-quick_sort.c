#include "sort.h"

/**
 * partition- perform lemuto partitioning
 * @arr: array to be sorted
 * @low: first array element
 * @high: last array element
 *
 * Return: void
 */
int partition(int arr[], int low, int high) {
	int j;
	int temp;
    int pivot = arr[high];
    int i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

/**
 * quicksort- performs sorting
 * @number: array to be sorted
 * @low: first array element
 * @high: last array element
 * @size: size of array
 *
 * Return: void
 */

void quicksort(int arr[], int low, int high, size_t size) {
    if (low < high) {
        int pivot = partition(arr, low, high);
	print_array(arr, size);
        quicksort(arr, low, pivot - 1, size);
        quicksort(arr, pivot + 1, high, size);
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
