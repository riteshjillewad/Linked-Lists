/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList22.c
// Description: Circular Singly Linked List -> InsertFirst() + Display + CountNodes() + InsertEnd()
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

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode->data = iNo;
    newnode->next = NULL;

    // Case 1: Empty List
    if((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;
        newnode->next = *head;                                                  // circular link
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
        (*tail)->next = *head;                                                  // maintain circularity
    }
}

void InsertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE temp = NULL;
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> next = NULL;

    // case 1: Empty CSL
    if((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;
        newnode -> next = *head;                                                // maintain circular link
    }
    // case 2: Single Node Present
    else
    {
        newnode -> next = *head;
        (*tail) -> next = newnode;                                             // maintain circular link
        *tail = newnode;
    }
}

void Display(PNODE head)
{
    PNODE temp = head;

    if(head != NULL)
    {
        do
        {
            printf(" | %d | <-> ", temp->data);
            temp = temp->next;
        } while(temp != head);
        printf("\n");
    }
}

int CountNodes(PNODE head)
{
    int iCount = 0;
    PNODE temp = head;

    if(head != NULL)
    {
        do
        {
            iCount++;
            temp = temp->next;
        } while(temp != head);
    }

    return iCount;
}

void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{
    PNODE temp = NULL;
    PNODE newnode = NULL;
    int iCount = 0;
    int iCnt = 0;

    iCount = CountNodes(*head);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position.\n");
        return;
    }

    // case 1: First Position
    if(iPos == 1)
    {
        InsertFirst(head, tail, iNo);
    }
    // case 2: Last Position
    else if(iPos == iCount + 1)
    {
        InsertLast(head, tail, iNo);
    }
    // case 3: Middle Position
    else 
    {
        newnode = (PNODE)malloc(sizeof(NODE));
        newnode->data = iNo;
        newnode->next = NULL;

        temp = *head;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head, &tail, 30);
    InsertFirst(&head, &tail, 20);
    InsertFirst(&head, &tail, 10);

    printf("Circular Linked List: \n");
    Display(head);

    iRet = CountNodes(head);
    printf("Total nodes: %d\n", iRet);

    InsertLast(&head, &tail, 40);
    InsertLast(&head, &tail, 50);
    InsertLast(&head, &tail, 60);

    printf("Circular Linked List: \n");
    Display(head);

    iRet = CountNodes(head);
    printf("Total nodes: %d\n", iRet);

    InsertAtPos(&head, &tail, 100, 4);

    printf("Circular Linked List: \n");
    Display(head);

    iRet = CountNodes(head);
    printf("Total nodes: %d\n", iRet);

    return 0;
}
