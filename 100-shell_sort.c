#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              Shell sort algorithm with Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Calculate initial gap using Knuth sequence: n+1 = n * 3 + 1 */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Start with largest gap and work down to gap of 1 */
    while (gap > 0)
    {
        /* Perform insertion sort for elements at gap interval */
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            
            /* Shift earlier gap-sorted elements up until correct location */
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            
            array[j] = temp;
        }

        /* Print array after each gap reduction */
        print_array(array, size);
        
        /* Calculate next gap using inverse Knuth sequence */
        gap = (gap - 1) / 3;
    }
}
