/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList30.c
// Description: Circular Doubly Linked List - InsertFirst() + Display() + CountNodes() + InsertLast() + InsertAtPos()
//                                            DeleteFirst()
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


void Display(PNODE head)
{
    PNODE temp = NULL;

    if(head != NULL)
    {
        temp = head;
        do
        {
            printf(" | %d | <-> ", temp -> data);
            temp = temp -> next;
        } while (temp != head);
        printf("\n");
    }
}


int CountNodes(PNODE head)
{
    PNODE temp = NULL;
    int iCount = 0;

    if(head != NULL)
    {
        temp = head;
        do
        {
            iCount++;
            temp = temp -> next;
        } while(temp != head);
    }
    return iCount;
}


void InsertFirst(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    // case 1: Empty CDLL
    if((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;
        
        newnode -> next = newnode;
        newnode -> prev = newnode;
    }
    // case 2: More than one node
    else
    {
        newnode -> next = *head;                                                // newnode pointing to old head
        newnode -> prev = *tail;                                                // newnode pointing to tail

        (*head) -> prev = newnode;                                              // old head pointing to newnode
        (*tail) -> next = newnode;                                              // tail pointing to newnode

        *head = newnode;                                                        // newnode is the new head
    }
}


void InsertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    // case 1: Empty CDLL
    if((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;

        newnode -> next = newnode;
        newnode -> prev = newnode;
    }
    // case 2: More than one node
    else
    {
        newnode -> prev = *tail;                                                    // newnode should point to current tail
        newnode -> next = *head;                                                    // newnode should point to current head

        (*tail) -> next = newnode;                                                  // old tail next should be newnode
        (*head) -> prev = newnode;                                                  // current head previous should be newnode

        *tail = newnode;                                                            // assign newnode as new tail
    }
}


void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{
    PNODE newnode = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    int iCnt = 0;

    iCount = CountNodes(*head);

    // validate the positions
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
        newnode -> data = iNo;
        newnode -> next = NULL;
        newnode -> prev = NULL;
         
        temp = *head;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newnode -> next = temp -> next;                             // newnode pointing to next of temp (temp next is node after newnode)
        newnode -> prev = temp;                                     // newnode prev should point to temp

        temp -> next -> prev = newnode;                           // node after newnode should point to newnode
        temp -> next = newnode;                                   // temp's next point to newnode (as temp is one position behind)                
    }
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head, &tail, 10);
    InsertFirst(&head, &tail, 20);
    InsertFirst(&head, &tail, 30);

    Display(head);

    iRet = CountNodes(head);
    printf("Number of elements in linked list are: %d\n", iRet);

    InsertLast(&head, &tail, 40);
    InsertLast(&head, &tail, 50);
    InsertLast(&head, &tail, 60);

    Display(head);

    iRet = CountNodes(head);
    printf("Number of elements in linked list are: %d\n", iRet);

    InsertAtPos(&head, &tail, 100, 4);
        
    Display(head);

    iRet = CountNodes(head);
    printf("Number of elements in linked list are: %d\n", iRet);

    return 0;
}