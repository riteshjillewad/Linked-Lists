# Doubly Linked List

![Image](https://github.com/user-attachments/assets/1af6eaff-f484-4fb8-970c-9cd6abc6540b)


A Doubly Linked List (DLL) is a linear data structure in which each element is called a node, and each node contains:

* Data – The value stored in the node.
* Prev – A pointer/reference to the previous node.
* Next – A pointer/reference to the next node.

Unlike singly linked lists, a doubly linked list allows traversal in both forward and backward directions.

---

## 🔹 Node Structure in C

```c
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
```

---

## 🔹 Memory Representation
```c
NULL ← [10 | * | *] ⇄ [20 | * | *] ⇄ [30 | * | NULL]
```
* Each node has links to both the previous and next nodes.
* The prev of the first node and next of the last node are NULL.

## 🔹 Basic Operations in Doubly Linked List

| Function Name        | Purpose                                               | Time Complexity |
|----------------------|--------------------------------------------------------|-----------------|
| `InsertFirst()`      | Inserts a new node at the beginning of the list       | O(1)            |
| `InsertLast()`       | Inserts a new node at the end of the list             | O(n)            |
| `InsertAtPos()`      | Inserts a node at a specific position                 | O(n)            |
| `DeleteFirst()`      | Removes the first node                                | O(1)            |
| `DeleteLast()`       | Removes the last node                                 | O(n)            |
| `DeleteAtPos()`      | Deletes a node from a given position                  | O(n)            |
| `DisplayForward()`   | Prints all elements from head to tail                 | O(n)            |
| `DisplayBackward()`  | Prints all elements from tail to head                 | O(n)            |
| `CountNodes()`       | Returns the total number of nodes in the list         | O(n)            |
| `Search()`           | Finds the position of a given element (if it exists)  | O(n)            |

---


## Author
Ritesh Jillewad <br>
01-07-2025
