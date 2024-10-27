#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    /* Loop through array size - 1 times */
    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        /* Last i elements are already in place */
        for (j = 0; j < size - i - 1; j++)
        {
            /* Compare adjacent elements */
            if (array[j] > array[j + 1])
            {
                /* Swap if they are in wrong order */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
                /* Print array after each swap */
                print_array(array, size);
            }
        }
        /* If no swapping occurred, array is sorted */
        if (swapped == 0)
            break;
    }
}
