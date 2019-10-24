//
//  array.c
//  
//
//  Created by Laura Gong on 10/24/19.
//

#include <stdio.h>
#include "array.h"

void Display(struct Array a)
{
    printf("Size: %d\n", a.size);
    printf("Actual length: %d\n", a.length);
    printf("Here are the elements you added: ");
    
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.array[i]);
    }
    printf("\n");
}
