/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList12.c
// Description: Doubly Linked List -> InsertFirst() + InsertLast()
// Input: void
// Output: void
// Date: 01-07-2025
// Author: Ritesh Jillewad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;


void InsertFirst(PPNODE head, int iNo)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> next = NULL;
    newnode -> prev = NULL;

    // case 1: Empty DLL
    if(*head == NULL)
    {
        *head = newnode;
    }
    // case 2: Contains one node
    else
    {
        newnode -> next = *head;
        (*head) -> prev = newnode;
        *head = newnode;
    }
}

void InsertLast(PPNODE head, int iNo)
{
    PNODE newnode = NULL;
    PNODE temp = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    // case 1: Empty DLL
    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}

int main()
{

    PNODE head = NULL;

    InsertFirst(&head, 21);
    InsertFirst(&head, 51);
    InsertFirst(&head, 81);

    Display(head);


    return 0;
}
