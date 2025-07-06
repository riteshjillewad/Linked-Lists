/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList33.c
// Description: Menu Diven Circular Doubly Linked List.
// Input: void
// Output: void
// Date: 05-07-2025
// Author: Ritesh Jillewad
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

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

    if (head != NULL) 
    {
        temp = head;

        do {
            printf(" | %d | <-> ", temp -> data);
            temp = temp -> next;
        } while (temp != head);
        printf("\n");
    }
}

int CountNodes(PNODE head) 
{
    int iCount = 0;

    PNODE temp = NULL;

    if (head != NULL) 
    {
        temp = head;

        do {
            iCount++;
            temp = temp -> next;
        } while (temp != head);
    }
    return iCount;
}

void InsertFirst(PPNODE head, PPNODE tail, int iNo) 
{

    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if (*head == NULL && *tail == NULL) 
    {
        *head = newnode;
        *tail = newnode;

        newnode -> next = newnode;
        newnode -> prev = newnode;
    } 
    else 
    {
        newnode -> next = *head;
        newnode -> prev = *tail;

        (*head) -> prev = newnode;
        (*tail) -> next = newnode;
        *head = newnode;
    }
}

void InsertLast(PPNODE head, PPNODE tail, int iNo) 
{

    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));

    newnode -> data = iNo;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if (*head == NULL && *tail == NULL) 
    {
        *head = newnode;
        *tail = newnode;
        newnode -> next = newnode; 
        newnode -> prev = newnode;
    } 
    else 
    {
        newnode -> prev = *tail;
        newnode -> next = *head;
        (*tail) -> next = newnode;
        (*head) -> prev = newnode;
        *tail = newnode;
    }
}

void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{

    PNODE newnode = NULL;
    int iCount = 0;
    
    iCount = CountNodes(*head);

    if (iPos < 1 || iPos > count + 1) 
    {
        printf("Invalid Position.\n");
        return;
    }

    if (iPos == 1) 
    {
        InsertFirst(head, tail, iNo);
    } 
    else if (iPos == count + 1) 
    {
        InsertLast(head, tail, iNo);
    } 
    else 
    {
        PNODE temp = *head;

        PNODE newnode = (PNODE)malloc(sizeof(NODE));
        newnode -> data = iNo;
        newnode -> next = NULL;
        newnode -> prev = NULL;

        for (int i = 1; i < iPos - 1; i++) 
        {
            temp = temp->next;
        }

        newnode -> next = temp -> next;
        newnode -> prev = temp;
        temp -> next -> prev = newnode;
        temp -> next = newnode;
    }
}

void DeleteFirst(PPNODE head, PPNODE tail) 
{

    PNODE temp = *head;

    if (*head == NULL && *tail == NULL) return;
    
    if (*head == *tail) 
    {
        free(*head);
        *head = *tail = NULL;
    } 
    else 
    {
        *head = (*head) -> next;
        (*head) -> prev = *tail;
        (*tail) -> next = *head;
        free(temp);
    }
}

void DeleteLast(PPNODE head, PPNODE tail) 
{

    PNODE temp = *tail;

    if ((*head == NULL) && (*tail == NULL))
    {
        return;
    }

    if (*head == *tail) 
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    } 
    else 
    {
        *tail = (*tail) -> prev;
        (*tail) -> next = *head;
        (*head) -> prev = *tail;

        free(temp);
    }
}

void DeleteAtPos(PPNODE head, PPNODE tail, int iPos) 
{

    int count = CountNodes(*head);

    if (iPos < 1 || iPos > count) 
    {
        printf("Invalid Position.\n");
        return;
    }

    if (iPos == 1) 
    {
        DeleteFirst(head, tail);
    } 
    else if (iPos == count) 
    {
        DeleteLast(head, tail);
    } 
    else 
    {
        PNODE temp = *head;
        for (int i = 1; i < iPos - 1; i++) 
        {
            temp = temp->next;
        }

        PNODE target = temp->next;

        temp -> next = target -> next;
        target -> next -> prev = temp;

        free(target);
    }
}

int main() 
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;

    while (1) 
    {
        printf("\n===== Circular Doubly Linked List Menu =====\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert at first: ");
                scanf("%d", &value);
                InsertFirst(&head, &tail, value);
                break;

            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &value);
                InsertLast(&head, &tail, value);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                InsertAtPos(&head, &tail, value, pos);
                break;

            case 4:
                DeleteFirst(&head, &tail);
                printf("First node deleted.\n");
                break;

            case 5:
                DeleteLast(&head, &tail);
                printf("Last node deleted.\n");
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                DeleteAtPos(&head, &tail, pos);
                break;

            case 7:
                printf("Circular Doubly Linked List: \n");
                Display(head);
                break;

            case 8:
                printf("Total nodes: %d\n", CountNodes(head));
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
