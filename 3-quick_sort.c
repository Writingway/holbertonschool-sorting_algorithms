#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: The array
 * @low: Start index
 * @high: End index
 * @size: Full array size
 *
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - recursive quicksort
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, p - 1, size);
        quick_sort_recursive(array, p + 1, high, size);
    }
}

/**
 * quick_sort - entry point
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
