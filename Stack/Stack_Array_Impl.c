#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
	unsigned int size;
	int top;
	int *array;
} Stack;

int isFull (Stack* stack);

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
	if (!isFull(stack))
	{
		stack->top = (stack->top)+1;
		stack->array[stack->top] = element;
	} else {
		printf("Stack is Full, element %d cannot be added\n", element);
	}
}

// pops top element off and returns value
int pop (Stack* stack)
{
    if (stack->top < 0)
    {
        printf("Can't pop empty stack.\n");
    }
    int top_element = stack->array[stack->top];
    stack->array[stack->top] = 0;  // 0 out the element - optional
    stack->top--;
    return top_element;
}

int isFull (Stack* stack)
{
    return (stack->top == stack->size-1) ? 1 : 0;
}

int isEmpty (Stack *stack)
{
    return stack->top == -1;
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
    printf("full/empty?: %d\n", isEmpty(new_stack));
	push(new_stack, 2);
    printf("full/empty?: %d\n", isEmpty(new_stack));
	push(new_stack, 10);
    push(new_stack, 20);
    push(new_stack, 30);
    push(new_stack, 40);
    push(new_stack, 50);
	Print_Stack(new_stack);
    int top_element = pop(new_stack);
    printf("Removed element: %d\n", top_element);
    Print_Stack(new_stack);
    return 0;
}
