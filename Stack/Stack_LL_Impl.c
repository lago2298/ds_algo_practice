#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* Linked list implementation of Stack- don't need to know exact size before building out the list
 Properties:
    1. Push and Pop from the top O(1)
    2. One struct for List Node and one struct for Stack itself
*/

// Remember linked lists are dynamic- useful for Stack where you don't know the size you want

// structs are default public, classes are default private

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct Stack {
    unsigned int size;
    ListNode *list;
} Stack;

Stack* CreateStack()
{
    // allocate memory for the Stack on the heap
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;  // initial size of 0
    stack->list = NULL;  // initialize head of list to NULL
    return stack;
}

// Push from the top- 2 cases-> 1. Insert first element 2. Insert at top
void push (Stack** stack, int element)
{
    // allocate memory for 1 ListNode element
    ListNode *node = malloc(sizeof(ListNode));
    // Set values of ListNode
    node->data = element;
    node->next = NULL;
    
    // add the new ListNode to the top of the Stack's list
    // 1. Current stack is empty
    if ((*stack)->list == NULL)
    {
        (*stack)->list = node;
    } else {
        // 2. Insert elment between head and current first element
        // save address of current first element
        ListNode *current_first = (*stack)->list;
        (*stack)->list = node;
        node->next = current_first;
    }
    
    ((*stack)->size)++; // increase size by 1
}

void DisplayElements (Stack* stack)
{
    // temporary pointer
    ListNode *tmp = stack->list;
    
    printf("Printing list: ");
    while(tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    printf("Size of list: %u\n", stack->size);
}

// delete stack by deleting list (iterate through each node) and then delete entire stack
// make sure to set all freed pointers to NULL
void delete();

int main()
{
    Stack *new_stack = CreateStack();
    DisplayElements(new_stack);
    push(&new_stack, 1);
    push(&new_stack, 4);
    push(&new_stack, 5);
    push(&new_stack, 8);
    DisplayElements(new_stack);
    return 0;
}
