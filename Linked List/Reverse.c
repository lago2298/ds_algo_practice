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

// MUST FREE WHAT YOU HAVE MALLOC'ED
void Delete (List **list, int element)
{
    List *current_ptr = *list;
    List *prev_ptr = *list;
    
    // 1st element delete case
     if (current_ptr != NULL && current_ptr->data == element)
     {
         *list = current_ptr->next;  // change the pointer to head to point to current_ptr->next
         free(current_ptr);  // free whatever current_ptr is pointing to
         return;
     }
    
    // everything else
    while (current_ptr != NULL && current_ptr->data != element)
    {
        prev_ptr = current_ptr; // keep track of current_ptr
        current_ptr = current_ptr->next; // keep searching
    }
    
    // you haven't found it and you reached the end
    if (current_ptr == NULL)
    {
        printf("Element not found so can't delete it\n");
        return;
    }
    
    // at this point, current_ptr-> data == element.  You have prev_ptr information saved
    prev_ptr->next = current_ptr->next;
    free(current_ptr);  // MUST FREE WHAT CURRENT_PTR POINTS TO
}

/*
 Algorithm:
 For non-1-element list and non-empty lists:
    List *tmp, *a, *b = *list;
    while (tmp != NULL)
    {
        b = tmp, tmp = b->next   // tmp tracks the current NEXT node before link swapping
        b->next = a
        a = b
    }
    // at this point, you've reached the end of the list, so fix head pointer
    (*list)->next = NULL
    *list = b
 */
void Reverse(List **list)
{
    List *tmp = *list, *a = *list, *b = *list;
    
    if (*list == NULL)
    {
        printf("This is an empty list, can't reverse it.\n");
        return;
    }
    
    if (a->next == NULL)
    {
        printf("This is a one element list, can't reverse it.\n");
        return;
    }
    
    while (tmp != NULL) // tmp is used because it's the farthest pointer and will be NULL when b is pointing to the last element
    {
        b = tmp;  // b goes up one node from a
        tmp = b->next;  // saves current NEXT value of element that b is pointing to
        b->next = a;  // b->next links back to a
        a = b;  // a goes up to b position
    }
    // at this point, you've reached the end of the list, so fix head pointer
    (*list)->next = tmp;
    *list = b;
}

int main()
{
    /*List *new_list = Create();
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
    Print_List(new_list);*/
    
    
    List *list = Create();
    Insert_Sorted(&list, 50);
    Print_List(list);
    Reverse(&list);
    Print_List(list);
    
    return 0;
}
