/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: LinkedList19.c
// Description: Static Circular Singly Linked List + Iteration Logic
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
    struct Node* next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

int main()
{

    PNODE head = NULL;
    PNODE tail = NULL;
    PNODE temp = NULL;
    PNODE newnode1 = NULL;
    PNODE newnode2 = NULL;
    PNODE newnode3 = NULL;

    newnode1 = (PNODE)malloc(sizeof(NODE));
    newnode2 = (PNODE)malloc(sizeof(NODE));
    newnode3 = (PNODE)malloc(sizeof(NODE));

    newnode1 -> data = 10;
    newnode2 -> data = 20;
    newnode3 -> data = 30;

    newnode1 -> next = newnode2;
    newnode2 -> next = newnode3;
    newnode3 -> next = newnode1;                                        // link last node's next to first node(forming circular link)

    head = newnode1;                                                    // head point to first node
    tail = newnode3;                                                    // tail point to last node

    temp = head;

    if(head != NULL)
    {
        do
        {
            printf(" | %d | <-> ", temp -> data);
            temp = temp -> next;
        } while(temp != head);
    }

    return 0;
}