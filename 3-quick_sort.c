#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 * @array: The array containing the elements
 * @size: Size of the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
    if (*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
        print_array(array, size);
    }
}

/**
 * lomuto_partition - Partitions array using Lomuto scheme
 * @array: Array to be partitioned
 * @low: Starting index of partition
 * @high: Ending index of partition
 * @size: Size of the array
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
                swap(&array[i], &array[j], array, size);
        }
    }
    if (array[i + 1] != array[high])
        swap(&array[i + 1], &array[high], array, size);
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
