//
//  main.c
//  
//For mergesort, you increase SPACE
// Time is still O(nlogn), but space is O(n + logn)
//  This is RECURSIVE mergesort
//

#include <stdio.h>

void mergesort (int *array, int low, int high);
void merge (int array[], int low, int mid, int high);


void merge (int *array, int low, int mid, int high)
{
    // create new array
    int helper_array[high];
    // merge two sides of the array, from low to mid and mid+1 to high
    
    // i is the index at the beginning of the first part of array, j is index pointing to second part of array, k is index for helper_array (also points to low)
    int i = low;
    int j = mid+1;
    int k = low;
    
    // make sure indexes don't go beyond their respective bounds
    while (j <= high && i <= mid)
    {
        // if element indexed by i is <= element pointed to by j, put element indexed at i in helper_array
        if (array[i] <= array[j])
        {
            helper_array[k++] = array[i++];
        } else {
            helper_array[k++] = array[j++];
        }
    }
    
    // For any remaining elements (if 2 sides are even)
    while (j <= high)
    {
        helper_array[k++] = array[j++];
    }
    
    while (i <= mid)
    {
        helper_array[k++] = array[i++];
    }
    
    // Read helper_array into array
    for (int m = 0; m <= high; m++)
    {
        array[m] = helper_array[m];
    }
    
    printf("Sorted part: ");
    for (int m = 0; m <= high; m++)
    {
        printf("%d ", array[m]);
    }
    printf("\n");
}

void mergesort (int *array, int low, int high)
{
    printf("TOP CALL- Mergesort: Low: %d, high: %d\n", low, high);
    if (low < high)  // this will stop mergesort at the base case where array is size 1
    {
        int middle = (low + high)/2;
        printf("1. Mergesort: Low: %d, middle: %d\n", low, middle);
        mergesort(array, low, middle);
        printf("2. Mergesort: Middle+1: %d, High: %d\n", middle+1, high);
        mergesort(array, middle+1, high);
        printf("3. Merge: Low: %d, middle: %d, high: %d\n", low, middle, high);
        merge(array, low, middle, high);
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
    
    mergesort(array, 0, arr_size-1);
    
    printf("Mergesort : ");
    for (int *ptr = array; ptr < array+arr_size; ptr++)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    
    
    return 0;
}
