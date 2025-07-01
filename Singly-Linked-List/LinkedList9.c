/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList9.c
// Description: This code contains menu driven singly linked list. 
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

    if(*head == NULL)                                                                   // if list is empty
    {
        *head = newnode;
    }

    else                                                                               // contains one node
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

    if (*head == NULL)                                                                  // if list is empty
    {
        *head = newnode;
    }

    else                                                                               // contains one node
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
        PNODE target = NULL;

        temp = *head;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
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
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;

    while(1)
    {
        printf("================== Singly Linked List ==================\n");
        printf("1. Insert at beginning.\n");
        printf("2. Insert at end.\n");
        printf("3. Insert at position.\n");
        printf("4. Delete first node.\n");
        printf("5. Delete last node.\n");
        printf("6. Delete node at position.\n");
        printf("7. Display linked list.\n");
        printf("8. Count total nodes.\n");
        printf("9. Search element.\n");
        printf("10. Exit.\n");
        printf("=========================================================\n");

        printf("Please enter your choice: ");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1: 
                printf("Enter value to insert at beginning: \n");
                scanf("%d", &iValue);
                InsertFirst(&head, iValue);
                break;

            case 2:
                printf("Enter value to insert at the end: \n");
                scanf("%d", &iValue);
                InsertLast(&head, iValue);
                break;

            case 3:
                printf("Enter value to insert: \n");
                scanf("%d", &iValue);
                printf("Enter position to insert: \n");
                scanf("%d", &iPos);
                InsertAtPos(&head, iValue, iPos);
                break;

            case 4:
                printf("Deleting the first node...\n");
                DeleteFirst(&head);
                printf("First node deleted successfully.\n");
                break;

            case 5:
                printf("Deleting the last node...\n");
                DeleteLast(&head);
                printf("Last node deleted successfully.\n");
                break;

            case 6:
                printf("Enter position to delete from.\n");
                scanf("%d", &iPos);
                DeleteAtPos(&head, iPos);
                printf("Node deleted successfully.\n");
                break;

            case 7:
                printf("Current Linked List: \n");
                Display(head);
                break;

            case 8:
                iRet = CountNodes(head);
                printf("Total number of nodes: %d\n", iRet);
                break;

            case 9:
                printf("Enter element to search: \n");
                scanf("%d", &iValue);
                iRet = Search(head, iValue);

                if(iRet != -1)
                {
                    printf("Element found at position: %d\n", iRet);
                }
                else
                {
                    printf("Element not found.\n");
                }
                break;

            case 10:
                printf("Exiting program. Thank You\n");
                exit(0);
            
            default:
                printf("Invalid Choice. Please try again.\n");

        }
    }

    return 0;
}
