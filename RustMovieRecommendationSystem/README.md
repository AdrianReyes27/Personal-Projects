# Movie Recommendation System (Rust)

A command-line movie recommendation application built in Rust that demonstrates filtering, sorting, user input handling, and structured data management using idiomatic Rust concepts.

This project was designed to showcase practical software engineering fundamentals including:

- Structs and enums
- Ownership and borrowing
- Pattern matching
- Vector manipulation
- Sorting and ranking algorithms
- Command-line interaction
- Data filtering
- Modular function design

---

# Features

- Search movies by:
  - Director
  - Genre
  - Maximum price
  - Minimum rating

- Sort results by:
  - Name
  - Director
  - Genre
  - Price
  - Rating

- Handles optional filters gracefully
- Case-insensitive matching
- Interactive CLI loop for repeated searches
- Stable secondary sorting for consistent rankings

---

# Technologies Used

- Rust
- Standard Library (`std`)
- Command-Line Interface (CLI)

---

# Project Structure


.
├── main.rs
└── README.md


Key components include:

| Component | Purpose |
|---|---|
| `Movie` struct | Represents movie data |
| `seed_data()` | Initializes movie dataset |
| `prompt()` | Handles user input |
| `parse_opt_*()` | Parses optional search criteria |
| `sort_movies()` | Sorts recommendation results |
| `print_results()` | Displays formatted output |

---

# Example Usage


Knowledge-Based Movie Recommender (Rust)

Director (exact match, e.g., Christopher Nolan) [none]:
Genre (e.g., Sci-Fi, Drama) [none]: Action
Max price (e.g., 9.99) [none]: 8.50
Min rating 0.0–5.0 (e.g., 4.2) [none]: 4.3
Sort by (name/director/genre/price/rating) [rating]: rating


Example output:


== Recommendations (2) ==

 1. Mad Max: Fury Road       | George Miller      | Action    | $8.49 | 4.7
 2. Skyfall                  | Sam Mendes         | Action    | $7.99 | 4.4


---

# Concepts Demonstrated

This project highlights several important programming concepts relevant to backend and systems development.

## Data Modeling
Uses Rust structs and enums to model movie data and sorting behavior.

## Ownership & Borrowing
Applies Rust’s memory safety model through immutable and mutable references.

## Pattern Matching
Leverages `match` expressions and `Option<T>` for safe input handling.

## Algorithmic Thinking
Implements custom filtering and ranking logic with secondary sorting rules.

## CLI Development
Demonstrates interactive terminal-based application development.

---

# Running the Project

## Prerequisites

Install Rust and Cargo:

https://www.rust-lang.org/tools/install

Verify installation:

```bash
rustc --version
cargo --version
```

---

## Run Locally

Clone the repository:

```bash
git clone <your-repository-url>
cd <repository-name>
```

Compile and run:

```bash
cargo run
```

Or compile directly:

```bash
rustc main.rs
./main
```

---

# Future Improvements

Potential enhancements for future versions:

- Persistent database integration
- Fuzzy search functionality
- Recommendation scoring algorithm
- User accounts and watchlists
- File-based movie imports
- API integration with external movie databases
- Web frontend using Rust frameworks
- Unit and integration testing

---

# Why I Built This

I created this project to strengthen my understanding of Rust fundamentals while building a practical recommendation system that demonstrates problem solving, program structure, and command-line application development.

The goal was to create a clean, maintainable project that showcases both programming fundamentals and software engineering practices in a portfolio setting.