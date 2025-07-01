/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList8.c
// Description: This code contains all the linked list functions 
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

    if(*head == NULL)
    {
        *head = newnode;
    }

    else
    {
        newnode -> next = *head;
        *head = newnode;
    }
}


void InsertLast(PPNODE head, int iNo)
{
    PNODE temp = NULL;
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode->data = iNo;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }

    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


int CountNodes(PNODE head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}


void InsertAtPos(PPNODE head, int iNo, int iPos)
{
    int iCount = CountNodes(*head);

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position.\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(head, iNo);
    }

    else if (iPos == iCount + 1)
    {
        InsertLast(head, iNo);
    }

    else
    {
        PNODE temp = NULL;
        PNODE newnode = NULL;

        newnode = (PNODE)malloc(sizeof(NODE));
        newnode->data = iNo;
        newnode->next = NULL;

        temp = *head;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}


void DeleteFirst(PPNODE head)
{
    if (*head == NULL)
        return;

    PNODE temp = NULL;

    temp = *head;
    *head = (*head)->next;
    free(temp);
}


void DeleteLast(PPNODE head)
{
    if (*head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = NULL;

        temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}


void DeleteAtPos(PPNODE head, int iPos)
{
    int iCount = CountNodes(*head);

    if ((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position.\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(head);
    }
    else if (iPos == iCount)
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp = NULL;

        temp = *head;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        PNODE target = temp->next;
        temp->next = target->next;
        free(target);
    }
}


void Display(PNODE head)
{
    while (head != NULL)
    {
        printf("| %d | -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int Search(PNODE head, int Key)
{
    int iPos = 1;

    while (head != NULL)
    {
        if (head->data == Key)
        {
            return iPos;
        }

        head = head->next;
        iPos++;
    }
    return -1;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 50);
    InsertFirst(&head, 40);
    InsertFirst(&head, 30);

    printf("Linked List after inserting at beginning:\n");
    Display(head);

    iRet = CountNodes(head);
    printf("Total nodes: %d\n", iRet);

    InsertLast(&head, 90);
    InsertLast(&head, 80);
    InsertLast(&head, 70);

    printf("\nLinked List after inserting at end:\n");
    Display(head);

    iRet = CountNodes(head);
    printf("Total nodes: %d\n", iRet);

    printf("\nInsert 100 at position 3:\n");
    InsertAtPos(&head, 100, 3);
    Display(head);

    printf("\nDelete first node:\n");
    DeleteFirst(&head);
    Display(head);

    printf("\nDelete last node:\n");
    DeleteLast(&head);
    Display(head);

    printf("\nDelete node at position 4:\n");
    DeleteAtPos(&head, 4);
    Display(head);

    printf("\nSearch for element 90:\n");
    int pos = Search(head, 90);

    if (pos != -1)
    {
        printf("Element found at position: %d\n", pos);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
