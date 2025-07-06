/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList25.c
// Description: Menu driven Circular Linked List
// Input: void
// Output: void
// Date: 04-07-2025
// Author: Ritesh Jillewad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void insertFirst(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newnode = (PNODE)malloc(sizeof(NODE));
    newnode->data = iNo;
    newnode->next = NULL;

    if ((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;
        newnode->next = *head;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
        (*tail)->next = *head;
    }
}

void insertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newnode = (PNODE)malloc(sizeof(NODE));
    newnode->data = iNo;
    newnode->next = NULL;

    if ((*head == NULL) && (*tail == NULL))
    {
        *head = newnode;
        *tail = newnode;
        newnode->next = *head;
    }
    else
    {
        newnode->next = *head;
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

void deleteFirst(PPNODE head, PPNODE tail)
{
    if ((*head == NULL) && (*tail == NULL))
    {
        return;
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        PNODE temp = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        free(temp);
    }
}

void deleteLast(PPNODE head, PPNODE tail)
{
    if ((*head == NULL) && (*tail == NULL))
    {
        return;
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        PNODE temp = *head;
        while (temp->next != *tail)
        {
            temp = temp->next;
        }
        free(*tail);
        *tail = temp;
        (*tail)->next = *head;
    }
}

void display(PNODE head)
{
    PNODE temp = head;

    if (head != NULL)
    {
        do
        {
            printf(" | %d | <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int countNodes(PNODE head)
{
    PNODE temp = head;
    int iCount = 0;

    if (head != NULL)
    {
        do
        {
            iCount++;
            temp = temp->next;
        } while (temp != head);
    }
    return iCount;
}

void insertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{
    int iCount = countNodes(*head);

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position.\n");
        return;
    }

    if (iPos == 1)
    {
        insertFirst(head, tail, iNo);
    }
    else if (iPos == iCount + 1)
    {
        insertLast(head, tail, iNo);
    }
    else
    {
        PNODE newnode = (PNODE)malloc(sizeof(NODE));
        newnode->data = iNo;
        newnode->next = NULL;

        PNODE temp = *head;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteAtPos(PPNODE head, PPNODE tail, int iPos)
{
    int iCount = countNodes(*head);

    if ((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position.\n");
        return;
    }

    if (iPos == 1)
    {
        deleteFirst(head, tail);
    }
    else if (iPos == iCount)
    {
        deleteLast(head, tail);
    }
    else
    {
        PNODE temp = *head;
        
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        PNODE target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iChoice = 0, iNo = 0, iPos = 0;

    while (1)
    {
        printf("\n==== Circular Singly Linked List Menu ====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Ending\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &iNo);
            insertFirst(&head, &tail, iNo);
            break;

        case 2:
            printf("Enter number: ");
            scanf("%d", &iNo);
            insertLast(&head, &tail, iNo);
            break;

        case 3:
            printf("Enter number: ");
            scanf("%d", &iNo);
            printf("Enter position: ");
            scanf("%d", &iPos);
            insertAtPos(&head, &tail, iNo, iPos);
            break;

        case 4:
            deleteFirst(&head, &tail);
            break;

        case 5:
            deleteLast(&head, &tail);
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &iPos);
            deleteAtPos(&head, &tail, iPos);
            break;

        case 7:
            display(head);
            break;

        case 8:
            printf("Total nodes = %d\n", countNodes(head));
            break;

        case 9:
            printf("Exiting and cleaning up memory...\n");
            freeList(&head, &tail);
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
