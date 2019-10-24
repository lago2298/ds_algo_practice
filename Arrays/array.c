//
//  array.c
//  
//
//  Created by Laura Gong on 10/24/19.
//

#include "array.h"
#include<stdlib.h>

int main()
{
    int size = 5;
    int* array;
    array = (int*)malloc(size*sizeof(int));
    array[0] = 10;
    array[1] = 12;
    array[3] = 24;
    printf("%d\n", array[3]);
    return 0;
}
