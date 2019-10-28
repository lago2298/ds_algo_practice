//
//  array.c
//
// (*p).a  == p->a
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

// Returns 1 if you can insert more elements, 0 if full
int Insert(struct Array *a, int index, int element)
{
	int current_index;
	// Check if index is unreasonable request (greater than size of array) or if array is full and can't have elements added
	if (index < a->size && a->length != a->size)
	{
		for(int i = a->length; i > index; i--)
		{
			a->array[i] = a->array[i-1];
		}
		a->array[index] = element;
		(a->length)++;
	} else {
		return 0;
	}
    return 1;
}

// Returns 1 if you can append more elements, 0 if full
int Append(struct Array *a, int element)
{
    if (a->size >= a->length + 1) //we still have room to add more elements
    {
        // Add element to the end
        a->array[a->length] = element;
        (a->length)++;
    } else {
        return 0;
    }
    return 1;
}

// Returns 1 if you can delete the element
int Delete (struct Array *a, int index)
{
	// check if index requested is reasonable
	if (index < a->length)
	{
		// Remove element
		for (int i = index; i < a->length; i++)
		{
			a->array[i] = a->array[i+1];
		}
		(a->length)--;
	} else {
		return 0;
	}
	return 1;
}
