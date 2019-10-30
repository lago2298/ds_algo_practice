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

// Best case scenario is O(nlogn)
// Worst case scenario for Quicksort is O(n^2) -> for the scenario where it's already sorted
// Then it's going to do n+(n-1)+(n-2)+...+2+1 = n*(n+1)/2 = https://www.reddit.com/r/visualizedmath/comments/8q76w4/the_summation_of_all_integers_from_1_to_n/
int partition(int a[], int low, int high)
{
    // pivot is the first element
	int pivot = a[low];
    int i = low + 1; // i starts at one above the first element since pivot is first element 
	int j = high;
    
    while (i <= j) // Only do this when i <= j -> once j passes i, then we swap pivot and j element
	{
		if (a[i] <= pivot) // i is looking for elements greater than pivot
		{
			i++;
		} else if (a[j] > pivot)  // j is looking for elements less than or equal to pivot
		{
			j--;
		} else {
			swap(&a[i], &a[j]);  // once we have reached this point, i is the index of an element greater than pivot, 
									// j is an index of element less than or equal to pivot, so we swap them
		}
	}
	swap(&a[j], &a[low]);  // at this point, we have identified all indexes j and below as being below or equal to the pivot, and 
							// all indexes i and above as being above the pivot
	return j;  // return the index where the pivot currently is (after the swap with original j)
}

void quicksort(int *array, int start_index, int end_index)
{
    if (start_index < end_index)
    {
        int pi = partition(array, start_index, end_index);
        quicksort(array, start_index, pi-1);
        quicksort(array, pi+1, end_index);
    }
}

int main()
{
    int array[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
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
