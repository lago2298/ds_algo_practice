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

void Insert_Sorted (List *list, int element)
{
	
}

int main()
{
    List *new_list = Create();
	Insert(&new_list, 5);
	Insert(&new_list, 20);
	Insert(&new_list, 30);
	Print_List(new_list);
    return 0;
}
