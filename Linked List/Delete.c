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
    printf("Printing list: ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
    printf("\n");
}

void Insert_Sorted (List **list, int element)
{
    List *new_element = malloc(sizeof(List)); // create new element
    
    // Fill out data and next pointer for new element
    new_element->data = element;
    new_element->next = NULL;
    
    List *tmp = *list;
    
    // Empty List case OR element is less than the first element (so element needs to be inserted BEFORE the first element in the list)
    if (*list == NULL || (*list)->data >= element)
    {
        *list = new_element;
        new_element->next = tmp;
    } else {
        // If it's not an empty list OR if the inserted element is greater than or equal to the first element
        while (tmp->next != NULL && tmp->next->data < element)
        {
            tmp = tmp->next; // keep searching
        }  // after this, you'll either end up at the end of the list OR the elememnt you need to insert at
        
        // link new element next pointer to point to current element's next element
        new_element->next = tmp->next; // will be NULL if at the end of the list
        tmp->next = new_element; // link current element to new element
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

void Delete (List **list, int element)
{
    List *tmp = *list;
    
    // Empty List case
    if (*list == NULL)
    {
        printf("Empty List!\n");
        return;
    }
    
    // 1st element delete case
     if ((*list)->data == element)
     {
         *list = (*list)->next;
         return;
     }
    
    // everything else
    while (tmp->next != NULL && tmp->next->data != element) // always one node in front of the last one
    {
        tmp = tmp->next; // keep searching
    }
    // you have found it or you reached the end
    if (tmp->next == NULL) // take care of reaching the end first
    {
        printf("Couldn't find element to delete it.\n");
    } else {
        tmp->next = tmp->next->next;
    }
}

int main()
{
    List *new_list = Create();
    Search(&new_list, 10);
    Delete(&new_list, 30);
	Insert_Sorted(&new_list, 200);
    Delete(&new_list, 200);
	Insert_Sorted(&new_list, 20);
	Insert_Sorted(&new_list, 2);
    Insert_Sorted(&new_list, 30);
	Print_List(new_list);
    Search(&new_list, 2);
    Search(&new_list, 200);
    Delete(&new_list, 200);
    Delete(&new_list, 30);
    Print_List(new_list);
    Delete(&new_list, 2);
    Print_List(new_list);
    Delete(&new_list, 20);
    Print_List(new_list);
    return 0;
}
