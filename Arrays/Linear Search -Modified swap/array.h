//
//  array.h
//  
//
//  Created by Laura Gong on 10/24/19.
//

#ifndef GUARD_array_h
#define GUARD_array_h

struct Array {
    int *array;
    int size; // size allocated
    int length; // actual length of array
};

void Display(struct Array a);

int Insert(struct Array *a, int index, int element);

int Append(struct Array *a, int element);

int Delete (struct Array *a, int index);

void swap (struct Array *a, int first_index, int second_index);

int Linear_Search (struct Array *a, int element);

#endif
