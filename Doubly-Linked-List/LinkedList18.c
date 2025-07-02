/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList18.c
// Description: Menu driven doubly linked list
// Input: void
// Output: void
// Date: 02-07-2025
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

// function to insert node at first
void InsertFirst(PPNODE head, int iNo)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    // case 1: If list is empty
    if(*head == NULL)
    {
        *head = newnode;                                            // newnode is the first node
    }
    // case 2: Single node is present
    else    
    {
        newnode -> next = *head;                                 // newnode's next should point to head(current node)
        (*head) -> prev = newnode;                              // current node's prev should point to the newnode
        *head = newnode;
    }
}

// function to insert node at end
void InsertLast(PPNODE head, int iNo)
{
    PNODE newnode = NULL;
    PNODE temp = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));
    newnode -> data = iNo;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    // case 1: If list is empty
    if(*head == NULL)
    {
        *head = newnode;
    }
    // case 2: If single node is present
    else
    {
        temp = *head;

        while(temp -> next != NULL)                                             // reach the last node
        {
            temp = temp -> next;
        }

        temp -> next = newnode;                                               // last node's next should point to newnode
        newnode -> prev = temp;                                               // newnode's prev should point to previous last node
    }
}

// function to insert node at a position
void InsertAtPos(PPNODE head, int iNo, int iPos)
{
    PNODE newnode = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    int iCnt = 0;

    iCount = CountNodes(*head);

    // validating the positions
    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position.\n");
        return;
    }

    // case 1: First Position
    if(iPos == 1)
    {
        InsertFirst(head, iNo);
    }
    // case 2: Last Position
    else if(iPos == iCount + 1)
    {
        InsertLast(head, iNo);
    }
    // case 3: Middle Position
    else
    {
        // Allocate only if we are inserting in the middle
        newnode = (PNODE)malloc(sizeof(NODE));
        newnode -> data = iNo;
        newnode -> next = NULL;
        newnode -> prev = NULL;

        temp = *head;

        // reach the one position back where you want to insert the node
        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        // temp is one position back where we want to insert the node, so it's next will be the last node
        newnode -> next = temp -> next;
        // newnode's previous should point to temp
        newnode -> prev = temp;
        // last node's prev should point to newnode
        temp -> next -> prev = newnode;
        // temp's next should point to newnode
        temp -> next = newnode;
    }
}

// function to delete first node
void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    // case 1: Empty DLL
    if(*head == NULL)
    {
        return;
    }
    // case 2: Contains single node
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    // case 3: Contains more than one node
    else
    {
        temp = *head;                                                               // store current head
        *head = (*head) -> next;                                                    // move head to next node
        free(temp);
        (*head)->prev = NULL;                                                       // remove the back link to old first node                                 
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    // case 1: Empty DLL
    if(*head == NULL)
    {
        return;
    }
    // case 2: Contains single node
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    // case 3: Contains more than one element
    else
    {
        temp = *head;

        while(temp -> next -> next != NULL)                                         // reach till second last node
        {
            temp = temp -> next;
        }
        free(temp -> next);                                                         // now temp is the second last node, so temp -> next is last node so free it
        temp -> next = NULL;
    }
}

// function to delete node at a position
void DeleteAtPos(PPNODE head, int iPos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0;
    int iCnt = 0;

    iCount = CountNodes(*head);

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position.\n");
        return;
    }

    // case 1: First Position
    if(iPos == 1)
    {
        DeleteFirst(head);
    }
    // case 2: Last Position
    else if(iPos == iCount)
    {
        DeleteLast(head);
    }
    // case 3: Middle Position
    else
    {
        temp = *head;

        // Iterate till the one position less than the target node
        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;                                              // target contains the node to be deleted (since temp is on one pos before the target node)

        temp -> next = target -> next;
        target -> next -> prev = temp;
        free(target);
    }

}

// function to display the doubly linked list
void Display(PNODE head)
{

    printf("NULL <->");
    while(head != NULL)
    {
        printf("| %d | <-> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}


// function to count the number of nodes in doubly linked list
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


// function to search an node in the doubly linked list
int Search(PNODE head, int iValue)
{
    int iPos = 1;

    while(head != NULL)
    {
        if(head->data == iValue)
        {
            return iPos;       // Element found, return position
        }
        head = head->next;
        iPos++;
    }

    return -1;  // Element not found
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
        printf("================== Doubly Linked List ==================\n");
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
