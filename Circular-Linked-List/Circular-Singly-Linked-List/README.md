# 🔁 Circular Singly Linked List in C

## 📌 Description
This project demonstrates a **menu-driven Circular Singly Linked List** implemented in the C programming language. It supports all major operations like insertion, deletion, traversal, and counting nodes.

---

## 🧠 What is a Circular Singly Linked List?

A **Circular Singly Linked List (CSLL)** is a type of linked list where:
- Each node contains:
  - `data`: holds the value
  - `next`: points to the next node
- The last node’s `next` pointer points back to the **head** node, forming a **circle**.

### ✅ Advantages:
- Efficient for applications requiring circular traversals (e.g., round-robin scheduling).
- No need to reset the pointer manually during circular iteration.

---

## ⚙️ Features Implemented

| Operation         | Description                               |
|------------------|-------------------------------------------|
| Insert First      | Add node at the beginning                |
| Insert Last       | Add node at the end                      |
| Insert At Position| Add node at any specific position        |
| Delete First      | Remove the first node                    |
| Delete Last       | Remove the last node                     |
| Delete At Position| Delete node at a given position          |
| Display           | Print the list circularly                |
| Count Nodes       | Count total number of nodes              |
| Free List         | Deallocate all nodes before exiting      |

---

## 🧪 Sample Menu

```
==== Circular Singly Linked List Menu ====

1. Insert at Beginning
2. Insert at Ending
3. Insert at Position
4. Delete First
5. Delete Last
6. Delete at Position
7. Display
8. Count Nodes
9. Exit
```



---

## 🔄 Data Structure Used

```c
struct Node
{
    int data;
    struct Node* next;
};
```

---

## 👨‍💻 Author
Ritesh Jillewad <br>
Date: 04-07-2025
