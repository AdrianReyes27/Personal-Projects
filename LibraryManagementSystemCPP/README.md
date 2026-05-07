# Library Management System (C++)

A command-line library management application built in C++ that demonstrates object-based data organization, input validation, vector manipulation, and CRUD operations using core software engineering principles.

This project was designed to showcase practical programming and data management concepts including:

- Structs and vectors
- Function overloading
- Input validation
- Pointer usage
- CRUD operations
- Search algorithms
- Menu-driven application design
- Command-line interaction

---

# Features

- Add books manually
- Add predefined book instances
- Display:
  - All books
  - Books by ID
  - Books by author
- Update book information
- Search for books
- Delete books
- Borrow books
- Return books
- Input validation for:
  - Integers
  - Strings
  - Empty input
  - Numeric characters in text fields

---

# Technologies Used

- C++
- Standard Template Library (STL)
- Vectors
- Structs
- Pointers
- Console-based user interface

Libraries used:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
```

---

# Project Structure

```text
.
├── main.cpp
└── README.md
```

Key components include:

| Component | Purpose |
|---|---|
| `Book` struct | Represents book data |
| `library` vector | Stores all books |
| `addBook()` | Adds books to the library |
| `displayBooks()` | Displays books using overloaded functions |
| `updateBook()` | Updates book information |
| `searchBook()` | Searches for books by ID |
| `deleteBook()` | Removes books from the library |
| `borrowBook()` | Handles borrowing logic |
| `returnBook()` | Handles returning logic |
| `getValidatedInt()` | Validates numeric input |
| `getValidatedString()` | Validates string input |

---

# Data Structure Overview

Each book contains:

```cpp
struct Book {
    int id;
    string title;
    string author;
    int publicationYear;
    int copiesAvailable;
};
```

Books are stored dynamically inside a `vector<Book>` container.

---

# Example Menu

```text
==== Library Menu ====

1. Add Book Manually
2. Add Book by Instance
3. Display All Books
4. Display Book by ID
5. Display Books by Author
6. Update Book
7. Search Book
8. Delete Book
9. Borrow Book
10. Return Book
0. Exit
```

---

# Example Output

```text
Book "NBA Facts and Trivia" added successfully.

--- Library Books ---

ID: 101
Title: NBA Facts and Trivia
Author: Curry
Year: 2016
Copies: 4
------------------
```

---

# Concepts Demonstrated

This project highlights several important programming concepts relevant to software engineering and backend development.

## Object-Based Data Modeling
Uses structs to organize and manage book-related data.

## STL Vector Usage
Stores and manages dynamic collections of books using vectors.

## Function Overloading
Implements multiple versions of `displayBooks()` and `addBook()` for flexible functionality.

## Input Validation
Prevents invalid user input through robust validation functions.

## Pointer Usage
Uses pointers for searching and modifying book records efficiently.

## CRUD Operations
Implements Create, Read, Update, and Delete functionality for managing library data.

## Menu-Driven Program Design
Demonstrates interactive command-line application flow and control structures.

---

# Running the Project

## Prerequisites

Install a C++ compiler such as:

- GCC
- Clang
- MSVC

Verify installation:

```bash
g++ --version
```

---

# Compile and Run

Compile the program:

```bash
g++ main.cpp -o library_system
```

Run the executable:

```bash
./library_system
```

---

# Future Improvements

Potential enhancements for future versions:

- File persistence for saving/loading books
- User authentication system
- ISBN support
- Sorting books by title or publication year
- Graphical user interface (GUI)
- Database integration
- Borrowing history tracking
- Unit and integration testing

---

# Why I Built This

I created this project to strengthen my understanding of C++ programming fundamentals, data management, and software design principles.

The goal was to build a practical CRUD-based application that demonstrates problem solving, data structure usage, input validation, and modular program organization relevant to software engineering and backend development roles.