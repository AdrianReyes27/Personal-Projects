# Apartment Linked List Manager (C)

A command-line apartment management program built in C that demonstrates the implementation of a singly linked list using dynamic memory allocation and pointer manipulation.

This project was designed to showcase core computer science and systems programming concepts including:

- Linked lists
- Dynamic memory allocation
- Structs and pointers
- Manual memory management
- Node insertion operations
- Traversal algorithms
- Command-line application development

---

# Features

- Create and manage a linked list of apartments
- Insert apartments at:
  - The beginning of the list
  - The end of the list
- Display all apartments in the list
- Dynamically allocate memory for new nodes
- Properly free allocated memory to prevent memory leaks
- Demonstrates pointer-based data structures in C

---

# Technologies Used

- C
- Standard C Library
  - `stdio.h`
  - `stdlib.h`
  - `string.h`

---

# Project Structure

```text
.
├── main.c
└── README.md
```

Key components include:

| Component | Purpose |
|---|---|
| `struct Apartment` | Represents a node in the linked list |
| `initList()` | Initializes an empty linked list |
| `insertAtStart()` | Inserts a node at the beginning |
| `insertAtEnd()` | Inserts a node at the end |
| `displayList()` | Traverses and displays the list |
| `freeList()` | Frees all dynamically allocated memory |

---

# Data Structure Overview

Each apartment node contains:

```c
struct Apartment {
    int number;
    float rent;
    int squareFeet;
    struct Apartment* next;
};
```

The `next` pointer links each apartment node to the next node in the list, forming a singly linked list.

---

# Example Output

```text
Apartment 101 | Rent: $1200.50 | Size: 750 sq ft
Apartment 102 | Rent: $1350.00 | Size: 800 sq ft
----------------
Apartment 101 | Rent: $1200.50 | Size: 750 sq ft
Apartment 102 | Rent: $1350.00 | Size: 800 sq ft
Apartment 103 | Rent: $1500.75 | Size: 900 sq ft
----------------
Apartment 100 | Rent: $1100.00 | Size: 700 sq ft
Apartment 101 | Rent: $1200.50 | Size: 750 sq ft
Apartment 102 | Rent: $1350.00 | Size: 800 sq ft
Apartment 103 | Rent: $1500.75 | Size: 900 sq ft

All apartments are now freed from memory.
```

---

# Concepts Demonstrated

This project highlights several important low-level programming concepts relevant to systems and backend development.

## Linked Lists
Implements a singly linked list from scratch using structs and pointers.

## Dynamic Memory Allocation
Uses `malloc()` and `free()` to manually manage memory allocation and deallocation.

## Pointer Manipulation
Demonstrates traversal and modification of linked data structures using pointers.

## Data Structures & Algorithms
Implements insertion operations and linear traversal algorithms.

## Memory Safety Awareness
Includes safety checks for failed memory allocation and proper cleanup of allocated memory.

---

# Running the Project

## Prerequisites

Install a C compiler such as:

- GCC
- Clang

Verify installation:

```bash
gcc --version
```

---

# Compile and Run

Compile the program:

```bash
gcc main.c -o apartment_manager
```

Run the executable:

```bash
./apartment_manager
```

---

# Future Improvements

Potential enhancements for future versions:

- Delete apartment nodes
- Search apartments by apartment number
- Sort apartments by rent or size
- Save apartment data to a file
- Load apartment data from a file
- Convert to a doubly linked list
- Add user-driven menu interaction
- Implement unit testing

---

# Why I Built This

I created this project to strengthen my understanding of low-level programming concepts and dynamic data structures in C.

The goal was to gain hands-on experience with linked lists, memory management, and pointer manipulation while building a practical application that demonstrates foundational computer science concepts relevant to software engineering and systems programming.
````
