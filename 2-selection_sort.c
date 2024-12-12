#include "sort.h"


/**
*selection_sort - Sorts an array of integers in ascending order
*using the Selection Sort algorithm.
*@array: The array to sort.
*@size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tempo;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

			if (min_index != i)
			{
				tempo = array[i];
				array[i] = array[min_index];
				array[min_index] = tempo;

				print_array(array, size);
			}
	}
}
