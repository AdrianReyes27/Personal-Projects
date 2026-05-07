#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Apartment node is created with a struct that holds data values and a pointer to the next node
struct Apartment {
    int number;
    float rent;
    int squareFeet;
    struct Apartment* next;
};

// Initializes an empty linked list that has no nodes 
struct Apartment* initList() {
    return NULL;
}

// Displays all apartments in linked list
void displayList(struct Apartment* head) {
    if (head == NULL) {
        printf("No apartments in the list.\n");
        return;
    }
    struct Apartment* current = head;
    while (current != NULL) {
        printf("Apartment %d | Rent: $%.2f | Size: %d sq ft\n",
               current->number, current->rent, current->squareFeet);
        current = current->next; // Goes to next value of list if possible 
    }
}

// Insert new node at the start of the list
void insertAtStart(struct Apartment** head_ref, int number, float rent, int squareFeet) {
    struct Apartment* newNode = malloc(sizeof(struct Apartment));
    if (!newNode) {
        printf("Memory allocation failed\n");  // Safety check in case malloc were to fail for some reason
        return;
    }
    newNode->number = number;  // Give it its values
    newNode->rent = rent;
    newNode->squareFeet = squareFeet;
    newNode->next = *head_ref; // Link new node to current head of list
    *head_ref = newNode; // Update head pointer to new node just  created
}

// Insert new node at the end of the list
void insertAtEnd(struct Apartment** head_ref, int number, float rent, int squareFeet) {
    struct Apartment* newNode = malloc(sizeof(struct Apartment));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->number = number;
    newNode->rent = rent;
    newNode->squareFeet = squareFeet;
    newNode->next = NULL; // Mkae it the last node

    if (*head_ref == NULL) {  // Makes the new node being inserted the had node if the list is already empty
        *head_ref = newNode;
        return;
    }

    struct Apartment* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;  // Makes current the last node if there are no more nodes found after it
}

// Free all apartments
void freeList(struct Apartment* head) {
    struct Apartment* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;  // Head pointer moves along forward to the next node in the list
        free(temp); // This value can now be freed after head was moved forward
    }
    printf("All apartments are now freed from memory.\n");
}

int main() {
    struct Apartment* list = initList(); // Creates a pointer named list who can point to nodes of type apartments

    // Function returns NULL meaning we know the list is empty and so we move forward
    
    
    // Insert apartments
    insertAtStart(&list, 101, 1200.50, 750); // Memory address of first node passed through
    insertAtEnd(&list, 102, 1350.00, 800);
    
    
    displayList(list);
    printf("----------------\n");
    
    insertAtEnd(&list, 103, 1500.75, 900);
    displayList(list);
    printf("----------------\n");
    
    insertAtStart(&list, 100, 1100.00, 700);

    // Display
    
    displayList(list);

    // Free memory
    freeList(list); // memory of total list is freed using the freeList function that frees memory individually

    return 0;
}
