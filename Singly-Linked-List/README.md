# 🔹Singly Linked List

A Singly Linked List (SLL) is a linear data structure in which each element is called a node, and each node contains:
* Data – The value stored in the node.
* Next – A pointer/reference to the next node in the list. <br>

Unlike arrays, linked lists do not require contiguous memory locations.

## 🔹 Node Structure in C
```c
struct Node
{
    int data;
    struct Node* next;
};
```
