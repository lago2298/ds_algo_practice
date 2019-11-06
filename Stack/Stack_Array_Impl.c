#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
	int size;
	int top;
	int *array;
} Stack;

Stack* init (int size) 
{
	// Create Stack object
	Stack *stack;
	stack->size = size;
	stack->top = -1;  // top = -1 when there are no elements
	stack->array = malloc(size*sizeof(int*));
	return stack;
}

void push (Stack* stack, int element)
{
	if (stack->top+1 != stack->size)  // change this to check isFull
	{
		stack->top = stack->top+1;
		stack->array[stack->top] = element;
	} else {
		printf("Stack is Full, element %d cannot be added", element);
	}
}

void Print_Stack (Stack* stack)
{
	printf("This is the stack: ");
	for (int i = 0; i < stack->size; i++)
	{
		printf("%d ", stack->array[i]);
	}
	printf("\n");
}

void delete_stack (Stack** stack)
{
	free(*stack);
}

int main()
{
    Stack *new_stack = init(5);
	push(new_stack, 2);
	push(new_stack, 10);
	Print_Stack(new_stack);
    return 0;
}
