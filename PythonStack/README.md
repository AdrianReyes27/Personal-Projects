# Apartment Stack Manager (Python)

A command-line apartment management application built in Python that demonstrates the implementation of a stack data structure using object-oriented programming principles.

This project was designed to showcase foundational software engineering and data structure concepts including:

- Object-oriented programming (OOP)
- Stack data structures
- Encapsulation
- Class methods
- LIFO (Last In, First Out) behavior
- List-based stack implementation
- Command-line interaction

---

# Features

- Create apartment objects with:
  - Apartment number
  - Rent price
  - Square footage

- Stack operations:
  - Push apartments onto the stack
  - Pop apartments from the stack
  - Peek at the top apartment
  - Check if stack is empty
  - Check if stack is full

- Fixed-capacity stack implementation
- User-friendly formatted output
- Prevents stack overflow and underflow

---

# Technologies Used

- Python 3
- Object-Oriented Programming (OOP)
- Built-in Python Lists

---

# Project Structure

```text
.
├── main.py
└── README.md
```

Key components include:

| Component | Purpose |
|---|---|
| `Apartment` class | Represents apartment data |
| `Stack` class | Implements stack behavior |
| `push()` | Adds an apartment to the stack |
| `pop()` | Removes the top apartment |
| `peek()` | Views the top apartment |
| `isFull()` | Checks stack capacity |
| `isEmpty()` | Checks if stack contains items |

---

# Data Structure Overview

The application uses a stack data structure with LIFO behavior:

```text
Last In → First Out
```

The most recently added apartment is always the first apartment removed.

Example:

```text
Push: 101
Push: 102
Push: 103

Pop → 103
```

---

# Example Output

```text
Is stack empty? True
Is stack full? False
--------------------

Apartment 101 | Rent: $1200.50 | Size: 750 sq ft pushed onto stack
Apartment 102 | Rent: $1350.00 | Size: 800 sq ft pushed onto stack
Apartment 103 | Rent: $1500.75 | Size: 900 sq ft pushed onto stack

Is stack empty? False
Is stack full? True
--------------------

Top apartment: Apartment 103 | Rent: $1500.75 | Size: 900 sq ft

Popped: Apartment 103 | Rent: $1500.75 | Size: 900 sq ft

Is stack empty? False
Is stack full? False
```

---

# Concepts Demonstrated

This project highlights several important programming concepts relevant to software engineering and backend development.

## Object-Oriented Programming
Uses Python classes and methods to model apartments and stack behavior.

## Data Structures
Implements a stack data structure with push, pop, and peek operations.

## Encapsulation
Keeps stack state and behavior organized within a dedicated class.

## Algorithmic Thinking
Demonstrates LIFO processing and controlled capacity management.

## State Management
Tracks the current top element and stack capacity manually.

---

# Running the Project

## Prerequisites

Install Python 3:

Verify installation:

```bash
python --version
```

or

```bash
python3 --version
```

---

# Run the Program

Execute the file:

```bash
python main.py
```

or

```bash
python3 main.py
```

---

# Future Improvements

Potential enhancements for future versions:

- Dynamic stack resizing
- User-driven menu system
- Apartment search functionality
- Save stack data to a file
- Load stack data from a file
- Graphical user interface (GUI)
- Unit testing implementation
- Exception handling improvements

---

# Why I Built This

I created this project to strengthen my understanding of object-oriented programming and core data structures in Python.

The goal was to gain practical experience implementing stack behavior manually while building a clean and maintainable application that demonstrates problem solving, program organization, and data structure fundamentals relevant to software engineering roles.
````
