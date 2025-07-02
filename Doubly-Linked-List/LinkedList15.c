/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList15.c
// Description: Doubly Linked List -> InsertFirst() + InsertLast() + Display() + Count() + DeleteFirst()
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
    newnode -> data = iNo;
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

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    // case 1: Empty DLL
    if(*head == NULL)
    {
        return;
    }
    // case 2: Contains one node
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    // case 3: Contains more than one node
    else
    {
        temp = *head;

        *head = (*head) -> next;                            // move head to next node
        free(temp);                                         // free the old first node
        (*head) -> prev = NULL;                             // remove the back link to the old first node
    }
}

int CountNodes(PNODE head)
{
    int iCount = 0;

    while(head != NULL)
    {
        iCount++;
        head = head -> next;
    }
    return iCount;
}

void Display(PNODE head)
{
    printf("NULL <->");
    while(head != NULL)
    {
        printf(" | %d | <-> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main()
{
    
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 21);
    InsertFirst(&head, 51);
    InsertFirst(&head, 81);

    InsertLast(&head, 101);
    InsertLast(&head, 201);
    InsertLast(&head, 301);

    Display(head);

    iRet = CountNodes(head);
    printf("Total number of nodes are: %d\n", iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = CountNodes(head);
    printf("Total number of nodes are: %d\n", iRet);

    return 0;
}
