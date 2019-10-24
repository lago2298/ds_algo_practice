//
//  array.h
//  
//
//  Created by Laura Gong on 10/24/19.
//

#ifndef GUARD_array_h
#define GUARD_array_h

struct Array {
    int* array;
    int size; // size allocated
    int length; // actual length of array
};

void Display(struct Array a);

#endif
