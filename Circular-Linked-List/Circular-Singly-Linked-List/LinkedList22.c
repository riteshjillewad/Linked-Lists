/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList22.c
// Description: Circular Singly Linked List -> InsertFirst() + Display + CountNodes()
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

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head, &tail, 10);
    InsertFirst(&head, &tail, 20);
    InsertFirst(&head, &tail, 30);

    printf("Circular Linked List: \n");
    Display(head);

    iRet = CountNodes(head);
    printf("Total nodes: %d\n", iRet);

    return 0;
}
