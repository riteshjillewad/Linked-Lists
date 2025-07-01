# 🔹 Singly Linked List

![Image](https://github.com/user-attachments/assets/e54ab697-3f97-4a85-afac-dea5d6eb2e35)

A **Singly Linked List (SLL)** is a linear data structure in which each element is called a **node**, and each node contains:
- **Data** – The value stored in the node.
- **Next** – A pointer/reference to the next node in the list.  

Unlike arrays, linked lists do not require contiguous memory locations.

---

## 🔹 Node Structure in C

```c
struct Node
{
    int data;
    struct Node* next;
};
```
---

## 🔹 Memory Representation
```
Head → [10 | *] → [20 | *] → [30 | NULL]
```
* The `Head` points to the first node.
* The `next` of the last node is NULL indicating the end of the list.

---

## 🔹 Basic Operations in Singly Linked List

| Function Name       | Purpose                                              | Time Complexity |
|---------------------|------------------------------------------------------|-----------------|
| `InsertFirst()`     | Inserts a new node at the beginning of the list      | O(1)            |
| `InsertLast()`      | Inserts a new node at the end of the list            | O(n)            |
| `InsertAtPos()`     | Inserts a node at a specific position                | O(n)            |
| `DeleteFirst()`     | Removes the first node                               | O(1)            |
| `DeleteLast()`      | Removes the last node                                | O(n)            |
| `DeleteAtPos()`     | Deletes a node from a given position                 | O(n)            |
| `Display()`         | Prints all elements of the list                      | O(n)            |
| `CountNodes()`      | Returns the total number of nodes in the list        | O(n)            |
| `Search()`          | Finds the position of a given element (if exists)    | O(n)            |

---

## Author
Ritesh Jillewad <br>
01-07-2025
