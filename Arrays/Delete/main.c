//
//  main.c
//  
//
//  Created by Laura Gong on 10/24/19.
//

#include "array.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct Array arr;  // Create a dynamic array
    
    printf("Please enter the size of the array you would like to create: ");
    scanf("%d", &arr.size); // Save array size from user input

    arr.array = (int*)malloc(arr.size*sizeof(int)); // allocate memory for array based on size-> pointer is on stack, actual array is on heap
    
    // Allow user to enter elements
    printf("Please enter the array elements followed by end of file: ");
    arr.length = 0; // Currently 0 elements
    
    for (int i = 0; i < arr.size; i++)
    {
        if (scanf("%d", &arr.array[i]) == 1) // if scanf successfully read in one item
        {
            arr.length++;
        }
    }
    
    if(Insert(&arr, 2, 100))
    {
        printf("Successfully inserted element!");
    } else {
        printf("You can't append more elements, your array is full or you're asking to insert an element at an impossible index!");
    }
    
    Display(arr);
	
	if(Delete(&arr, 1))
    {
        printf("Successfully deleted element!");
    } else {
        printf("You can't delete more elements, you're asking to delete an element at an impossible index!");
    }
	
	Display(arr);
	
	printf("Press ENTER key to Continue\n");
	getchar();
    
    return 0;
}
