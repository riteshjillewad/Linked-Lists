# 🔁 Circular Doubly Linked List in C

## 📌 Description
This project implements a **Menu Driven Circular Doubly Linked List** in C. It supports various operations like insertion, deletion, display, and counting the number of nodes.

---

## 📘 Understanding Linked Lists

### 1️⃣ Singly Linked List
A singly linked list is a linear data structure where each node contains:
- `data`: the value
- `next`: a pointer to the next node

📌 Traversal is only possible in the forward direction.

---

### 2️⃣ Circular Singly Linked List
A circular singly linked list is similar to a singly linked list but with a twist:
- The `next` pointer of the last node points back to the **head** node instead of `NULL`.

✅ **Advantages**:
- Circular traversal without needing to reset the pointer.
- Useful in cyclic scheduling or buffer handling.

---

### 3️⃣ Circular Doubly Linked List
A circular doubly linked list is an advanced version:
- Each node has two pointers:
  - `next`: points to the next node
  - `prev`: points to the previous node
- The list is circular in nature:
  - `head->prev` points to the tail
  - `tail->next` points back to the head

✅ **Advantages over Circular Singly Linked List**:
- **Bidirectional Traversal**
- More efficient insertion/deletion operations at both ends.

---

## 🛠️ Features of the Project

- ✅ Insert node at the beginning
- ✅ Insert node at the end
- ✅ Insert node at a specific position
- ✅ Delete first node
- ✅ Delete last node
- ✅ Delete node at a specific position
- ✅ Display the list
- ✅ Count total number of nodes

---


---

## ▶️ How It Works

### 🔸 Sample Menu (in terminal)

```
===== Circular Doubly Linked List Menu =====

Insert First

Insert Last

Insert at Position

Delete First

Delete Last

Delete at Position

Display List

Count Nodes

Exit

shell
Copy
Edit
```


