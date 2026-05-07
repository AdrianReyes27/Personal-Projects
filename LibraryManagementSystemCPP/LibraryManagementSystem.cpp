#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// Struct and vector
struct Book {
    int id;
    string title;
    string author;
    int publicationYear;
    int copiesAvailable;
};

vector<Book> library;

// Predefined Book Instances
Book book1 = {101, "NBA Facts and Trivia", "Curry", 2016, 4};
Book book2 = {102, "How to Build a House", "Smith", 1982, 5};
Book book3 = {103, "How to Paint", "Thomas", 2006, 7};

// Helper functions for input validation

// Validate integer input
int getValidatedInt(const string &prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value; // Tries to read an integer into value variable
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n'); // Skips the rest of the line up to 10,000 charcters or
            // until it hits a new line so that any bad input does not interfere with the next input
        } else {
            cin.ignore(10000, '\n'); // if input is valid, we ignore the rest of the line and return the integer
            return value;
        }
    }
}

// Validate non empty string that does not contain numbers
string getValidatedString(const string &prompt) {
    string input; //stores user input 
    while (true) {
        cout << prompt;
        getline(cin, input); //Read the whole line of input including spaces

        // Trim leading/trailing spaces
        
        // size_t is an unisgned integer type that can only hold non-negative numbers
        // This is used since size or index can not be non-negative
        
        size_t first = input.find_first_not_of(' '); // This is the index of the first non-space character
        size_t last = input.find_last_not_of(' '); // This is the index of the last non-space character
        input = (first == string::npos) ? "" : input.substr(first, last - first + 1); // If string was only
        // spaces, input is set to an empty string
        // Else, a substring is extracted that gives us the original input without leading or trialing
        // spaces

        bool isValid = !input.empty(); // Marks input as invalid if empty after trimming
        for (char c : input) { // Goes through each charcter in input
            if (isdigit(c)) { // If title is a number then the input is invalid
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Invalid input. Please enter letters only and not empty.\n";
        } else {
            return input;
        }
    }
}

// Library Functions


// Using & (reference not a copy) and const is an efficient way to read the string without copying it

void addBook(int id, string title, string author, int year, int copies) {
    for (const Book &b : library) {
        if (b.id == id) {
            cout << "Error: A book with ID " << id << " already exists.\n";
            return;
        }
    }
    Book newBook = {id, title, author, year, copies};
    library.push_back(newBook);
    cout << "Book \"" << title << "\" added successfully.\n";
}

void addBook(Book b) {
    for (const Book &book : library) {
        if (book.id == b.id) {
            cout << "Error: A book with ID " << b.id << " already exists.\n";
            return;
        }
    }
    library.push_back(b);
    cout << "Book \"" << b.title << "\" added successfully.\n";
}

void displayBooks() {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }
    cout << "\n--- Library Books ---\n";
    for (const Book &b : library) {
        cout << "ID: " << b.id << "\nTitle: " << b.title
             << "\nAuthor: " << b.author
             << "\nYear: " << b.publicationYear
             << "\nCopies: " << b.copiesAvailable << "\n------------------\n";
    }
}

void displayBooks(int bookId) {
    bool found = false;
    for (const Book &b : library) {
        if (b.id == bookId) {
            cout << "ID: " << b.id << "\nTitle: " << b.title
                 << "\nAuthor: " << b.author
                 << "\nYear: " << b.publicationYear
                 << "\nCopies: " << b.copiesAvailable << "\n------------------\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "No book found with ID " << bookId << ".\n";
}

void displayBooks(const string &authorName) {
    bool found = false;
    for (const Book &b : library) {
        if (b.author == authorName) {
            cout << "ID: " << b.id << "\nTitle: " << b.title
                 << "\nAuthor: " << b.author
                 << "\nYear: " << b.publicationYear
                 << "\nCopies: " << b.copiesAvailable << "\n------------------\n";
            found = true;
        }
    }
    if (!found) cout << "No books found by author " << authorName << ".\n";
}

void updateBook(int bookId, const string &newTitle, const string &newAuthor, int newYear) {
    bool found = false;
    for (Book &b : library) {
        if (b.id == bookId) {
            b.title = newTitle;
            b.author = newAuthor;
            b.publicationYear = newYear;
            cout << "Book with ID " << bookId << " updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Error: No book found with ID " << bookId << ".\n";
}

Book* searchBook(int bookId) {
    for (Book &b : library) {
        if (b.id == bookId) return &b;
    }
    cout << "Error: No book found with ID " << bookId << ".\n";
    return nullptr;
}

void deleteBook(int bookId) {
    bool found = false;
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->id == bookId) {
            library.erase(it);
            cout << "Book with ID " << bookId << " deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Error: No book found with ID " << bookId << ".\n";
}

void borrowBook(int bookId, int numCopies = 1) {
    Book* bookPtr = searchBook(bookId);
    if (bookPtr != nullptr) {
        if (bookPtr->copiesAvailable >= numCopies) {
            bookPtr->copiesAvailable -= numCopies;
            cout << numCopies << " copy/copies of \"" << bookPtr->title << "\" borrowed successfully.\n";
        } else {
            cout << "Error: Only " << bookPtr->copiesAvailable << " copy/copies available.\n";
        }
    }
}

void returnBook(int bookId, int numCopies = 1) {
    Book* bookPtr = searchBook(bookId);
    if (bookPtr != nullptr) {
        bookPtr->copiesAvailable += numCopies;
        cout << numCopies << " copy/copies of \"" << bookPtr->title << "\" returned successfully.\n";
    }
}

// --- Main Menu ---
int main() {
    int choice;

    do {
        cout << "\n==== Library Menu ====\n";
        cout << "1. Add Book Manually\n";
        cout << "2. Add Book by Instance\n";
        cout << "3. Display All Books\n";
        cout << "4. Display Book by ID\n";
        cout << "5. Display Books by Author\n";
        cout << "6. Update Book\n";
        cout << "7. Search Book\n";
        cout << "8. Delete Book\n";
        cout << "9. Borrow Book\n";
        cout << "10. Return Book\n";
        cout << "0. Exit\n";
        choice = getValidatedInt("Enter your choice: ");

        switch(choice) {
            case 1: { // Manual add
                int id = getValidatedInt("Enter Book ID: ");
                string title = getValidatedString("Enter Title: ");
                string author = getValidatedString("Enter Author: ");
                int year = getValidatedInt("Enter Publication Year: ");
                int copies = getValidatedInt("Enter Copies Available: ");
                addBook(id, title, author, year, copies);
                break;
            }
            case 2: { // Add by instance
                string instanceName;
                cout << "Enter book instance name (book1, book2, book3): ";
                getline(cin, instanceName);

                if (instanceName == "book1") addBook(book1);
                else if (instanceName == "book2") addBook(book2);
                else if (instanceName == "book3") addBook(book3);
                else cout << "Invalid instance name. Please enter book1, book2, or book3.\n";
                break;
            }
            case 3:
                displayBooks();
                break;
            case 4: {
                int id = getValidatedInt("Enter Book ID: ");
                displayBooks(id);
                break;
            }
            case 5: {
                string author = getValidatedString("Enter Author Name: ");
                displayBooks(author);
                break;
            }
            case 6: {
                int id = getValidatedInt("Enter Book ID to update: ");
                string title = getValidatedString("Enter New Title: ");
                string author = getValidatedString("Enter New Author: ");
                int year = getValidatedInt("Enter New Publication Year: ");
                updateBook(id, title, author, year);
                break;
            }
            case 7: {
                int id = getValidatedInt("Enter Book ID to search: ");
                Book* book = searchBook(id);
                if (book != nullptr)
                    cout << "Found Book: " << book->title << " by " << book->author
                         << ", Copies: " << book->copiesAvailable << endl;
                break;
            }
            case 8: {
                int id = getValidatedInt("Enter Book ID to delete: ");
                deleteBook(id);
                break;
            }
            case 9: {
                int id = getValidatedInt("Enter Book ID to borrow: ");
                int num = getValidatedInt("Enter number of copies (default 1): ");
                borrowBook(id, num);
                break;
            }
            case 10: {
                int id = getValidatedInt("Enter Book ID to return: ");
                int num = getValidatedInt("Enter number of copies (default 1): ");
                returnBook(id, num);
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }

    } while(choice != 0);

    return 0;
}
