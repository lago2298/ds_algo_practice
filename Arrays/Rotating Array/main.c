//
//  main.c
//  
//
//  Created by Laura Gong on 10/29/19.
//

#include <stdlib.h>
#include <stdio.h>

void rotate(int* nums, int numsSize, int k){
    
    int mod = k%numsSize;
    
    if (k!=0){
        for (int *ptr = nums; ptr < nums+numsSize; ptr++)  // ptr++ moves to the next int position (takes type into consideration)
        {
                printf("%d\n", *(ptr+mod));
        }
    }
}

int main()
{
    int array[5] = {1,2,3,4,5};
    int *p = array;
    
    rotate(p, 5, 2);
    
    
    return 0;
}
