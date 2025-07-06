
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList19.c
// Description: Circular Singly Linked List -> InsertFirst() Logic
// Input: void
// Output: void
// Date: 03-07-2025
// Author: Ritesh Jillewad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void InsertFirst(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> next = NULL;

    // case 1: Empty CSL
    if((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;
        newnode -> next = *head;                            // circular link
    }
    // case 2: Contains Single Node
    else
    {
        newnode -> next = *head;                            // newnode's next point to old head
        *head = newnode;                                    // new head is current newnode (head points to newnode)
        (*tail) -> next = newnode;                          // tail's next should point to newnode to maintain circular link
    }
}

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head, &tail, 10);
    InsertFirst(&head, &tail, 20);
    InsertFirst(&head, &tail, 30);

    return 0;
}