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

int partition(int *array, int low, int high)
{
    // pivot is the last element
    int pivot = *(array+high);
    int i = low - 1;
    
    for (int j = low; j < high - 1; j++)
    {
        if (*(array+j) < pivot)
        {
            i++;
            swap(array+i, array+j);
        }
    }
    swap(array+i+1, array+high);
    return i+1;
}

void quicksort(int *array, int start_index, int end_index)
{
    if (start_index < end_index)
    {
        int pi = partition(array, start_index, end_index);
        
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
    
    quicksort(array, 0, arr_size);
    
    printf("Quicksort : ");
    for (int *ptr = array; ptr < array+arr_size; ptr++)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    
    
    return 0;
}
