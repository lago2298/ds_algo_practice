//
//  main.c
//  
//
//  Created by Laura Gong on 10/29/19.
//

#include <stdlib.h>
#include <stdio.h>

void swap (int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void reverse(int *array, int start_index, int end_index)
{
    int start_ptr = start_index;
    int end_ptr = end_index;
    
    while (start_ptr < end_ptr)
    {
        swap(array+start_ptr, array+end_ptr);
        start_ptr++;
        end_ptr--;
    }
}

void right_rotate(int *nums, int numsSize, int k){
    
    // Algorithm:
    // Reverse whole array, then reverse 0 to k-1 and then reverse k to numSize-1
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}

void left_rotate(int *nums, int numsSize, int k)
{
    // Algorithm:
    // Reverse whole array, then reverse 0 to k and then reverse k+1 to numSize-1
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k);
    reverse(nums, k+1, numsSize-1);
}

int main()
{
    int array[7] = {1,2,3,4,5,6,7};
    int arr_size = sizeof(array)/sizeof(array[0]);
    
    printf("Original array : ");
    for (int *ptr = array; ptr < array+arr_size; ptr++)  // ptr++ moves to the next int position (takes type into consideration)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    right_rotate(array, arr_size, 3);
    
    printf("Right shift by 3: ");
    for (int *ptr = array; ptr < array+arr_size; ptr++)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    int array2[7] = {1,2,3,4,5,6,7};
    int arr_size2 = sizeof(array)/sizeof(array[0]);
    
    printf("Original array: ");
    for (int *ptr = array2; ptr < array2+arr_size2; ptr++)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    left_rotate(array2, arr_size2, 3);
    
    printf("Left shift by 3: ");
    for (int *ptr = array2; ptr < array2+arr_size2; ptr++)
    {
        printf("%d ", *ptr);
    }
    
    printf("\n");
    
    return 0;
}
