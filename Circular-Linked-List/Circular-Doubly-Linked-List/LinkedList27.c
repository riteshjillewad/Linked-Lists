/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList27.c
// Description: Static Circular Doubly Linked List
// Input: void
// Output: void
// Date: 05-07-2025
// Author: Ritesh Jillewad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

int main()
{

    PNODE head = NULL;
    PNODE tail = NULL;
    PNODE newnode1 = NULL;
    PNODE newnode2 = NULL;
    PNODE newnode3 = NULL;

    // Allocating the memory
    newnode1 = (PNODE)malloc(sizeof(NODE));
    newnode2 = (PNODE)malloc(sizeof(NODE));
    newnode3 = (PNODE)malloc(sizeof(NODE));

    // Initializing the data
    newnode1 -> data = 10;
    newnode2 -> data = 20;
    newnode3 -> data = 30;

    // Forward Links (next)
    newnode1 -> next = newnode2;
    newnode2 -> next = newnode3;
    newnode3 -> next = newnode1;

    // Backward Links (prev)
    newnode1 -> prev = newnode3;
    newnode2 -> prev = newnode1;
    newnode3 -> prev = newnode2;

    // Setting the head and tail
    head = newnode1;
    tail = newnode3;

    // Printing the Linked List
    printf("%d\n", head -> data);
    printf("%d\n", head -> next -> data);
    printf("%d\n", head -> next -> next -> data);

    printf("%d\n", tail -> data);
    printf("%d\n", tail -> next -> data);
    printf("%d\n", tail -> next -> next -> data);

    return 0;

}