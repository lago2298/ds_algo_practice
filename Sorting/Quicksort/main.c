//
//  main.c
//  
//
//  Created by Laura Gong on 10/29/19.
//

#include <stdlib.h>
#include <stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int a[], int low, int high)
{
    // pivot is the first element
    int pivot = a[low];
    int i = low + 1;
	int j = high;
	
	printf("%d\n", pivot);
    
    while (i <= j)
	{
		if (a[i] <= pivot)
		{
			i++;
		} else if (a[j] > pivot)
		{
			j--;
		} else {
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[j], &a[low]);
	return j;
}

void quicksort(int *array, int start_index, int end_index)
{
    if (start_index < end_index)
    {
        int pi = partition(array, start_index, end_index);
        printf("pivot:%d\n", pi);
        quicksort(array, start_index, pi - 1);
        quicksort(array, pi+1, end_index);
    }
}

int main()
{
    int array[] = {10, 7, 8, 9, 1, 5};
    int arr_size = sizeof(array)/sizeof(array[0]);
    
    printf("Original array : ");
    for (int *ptr = array; ptr < array+arr_size; ptr++)  // ptr++ moves to the next int position (takes type into consideration)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    quicksort(array, 0, arr_size-1);
    
    printf("Quicksort : ");
    for (int *ptr = array; ptr < array+arr_size; ptr++)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    
    
    return 0;
}
