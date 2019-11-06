#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
	unsigned int size;
	int top;
	int *array;
} Stack;

Stack* init (int size) 
{
	// Create Stack object
	Stack *stack = malloc(sizeof(Stack));  // allocate memory for entire stack
	stack->size = size;
	stack->top = -1;  // top = -1 when there are no elements
    // use calloc instead of malloc to initialize everything to 0
	stack->array = calloc(size,sizeof(int));  // allocate memory for array that serves as stack
	return stack;
}

void push (Stack* stack, int element)
{
	if (((stack->top)+1) != stack->size-1)  // change this to check isFull
	{
		stack->top = (stack->top)+1;
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
