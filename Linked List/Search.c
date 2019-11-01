//
//  main.c
//
//  This program creates a linked list and inserts an element into the linked list
//  Linked list is a good DYNAMIC data structure
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} List;  // List = typedef name for struct Node 

// Creates head pointer to List but pointing to NULL 
List* Create()
{
	List *head = NULL;  // head pointer to List
	return head;
}

// Insert an element to the front
void Insert(List **list, int element)
{
	// don't really need malloc casting in C
	List *new_element = (List *)malloc(sizeof(List)); // allocates size for one List node
	new_element->data = element;
	new_element->next = *list;
	*list = new_element;
}

void Print_List (List *list)
{
	List *tmp = list;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void Insert_Sorted (List **list, int element)
{
    List *new_element = malloc(sizeof(List)); // create new element
    List *tmp = *list;
    // Empty List case
    if (*list == NULL)
    {
        *list = new_element;
        new_element->data = element;
        new_element->next = NULL;
    } else {  // Not empty list
        // check first element
        if (tmp->data >= element)
        {
            // Insert as the first element
            *list = new_element;
            new_element-> data = element;
            new_element->next = tmp;
            return;
        }
        // If it shouldn't be sorted before the first element, then:
        while (tmp->next != NULL)
        {
            if (tmp->next->data >= element)
            {
                // link new element next pointer to point to current next element
                new_element->data = element;
                new_element->next = tmp->next;
                tmp->next = new_element; // link current element to new element
                return;
            } else {
                tmp = tmp->next;
            }
        }
        // If reached end of list, then insert at end
        tmp->next = new_element;
        new_element->data = element;
        new_element->next = NULL;
        
    }
}

void Search (List **list, int element)
{
    // Empty list case
    if (*list == NULL)
    {
        printf("Empty List!\n");
        return;
    }
    
    List *tmp = *list;
    while (tmp != NULL)
    {
        if (tmp->data == element)
        {
            printf("Found element! Element is: %d\n", tmp->data);
            return;
        } else {
            tmp = tmp->next;
        }
    }
    printf("Did not find element!\n");
}

int main()
{
    List *new_list = Create();
    Search(&new_list, 10);
	Insert_Sorted(&new_list, 200);
	Insert_Sorted(&new_list, 20);
	Insert_Sorted(&new_list, 2);
    Insert_Sorted(&new_list, 30);
	Print_List(new_list);
    Search(&new_list, 2);
    Search(&new_list, 10);
    return 0;
}
