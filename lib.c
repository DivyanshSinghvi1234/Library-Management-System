#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to represent a book
struct Book {
    int id;
    char title[100];
    char author[100];
    int isAvailable; // 1 = available, 0 = borrowed
};

// Define a structure to represent a library member
struct Member {
    int id;
    char name[100];
};

// Function to add a new book to the library
void addBook(struct Book books[], int *bookCount) {
    printf("Enter Book ID: ");
    scanf("%d", &books[*bookCount].id);
    
    printf("Enter Book Title: ");
    scanf("%s", books[*bookCount].title);
    
    printf("Enter Author: ");
    scanf("%s", books[*bookCount].author);
    
    books[*bookCount].isAvailable = 1; // Newly added book is always available
    
    printf("Book added successfully!\n\n");
    (*bookCount)++;
}

// Function to display all books in the library
void displayBooks(struct Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books in the library.\n\n");
        return;
    }

    printf("Book ID\tTitle\t\t\tAuthor\t\t\tAvailability\n");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", books[i].id, books[i].title, books[i].author, 
               books[i].isAvailable ? "Available" : "Borrowed");
    }
    printf("\n");
}

// Function to borrow a book
void borrowBook(struct Book books[], int bookCount) {
    int id;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &id);
    
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].isAvailable) {
                books[i].isAvailable = 0;
                printf("You have successfully borrowed '%s'.\n\n", books[i].title);
            } else {
                printf("Sorry, the book is already borrowed.\n\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n\n", id);
}

// Function to return a book
void returnBook(struct Book books[], int bookCount) {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (!books[i].isAvailable) {
                books[i].isAvailable = 1;
                printf("You have successfully returned '%s'.\n\n", books[i].title);
            } else {
                printf("The book is already available in the library.\n\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n\n", id);
}

// Function to search for a book by title
void searchBook(struct Book books[], int bookCount) {
    char title[100];
    printf("Enter Book Title to search: ");
    scanf("%s", title);
    
    for (int i = 0; i < bookCount; i++) {
        if (strcasecmp(books[i].title, title) == 0) {
            printf("Book found!\n");
            printf("ID: %d, Title: %s, Author: %s, Status: %s\n\n", books[i].id, books[i].title, 
                   books[i].author, books[i].isAvailable ? "Available" : "Borrowed");
            return;
        }
    }
    printf("Book with title '%s' not found.\n\n", title);
}

// Function to add a new member
void addMember(struct Member members[], int *memberCount) {
    printf("Enter Member ID: ");
    scanf("%d", &members[*memberCount].id);
    
    printf("Enter Member Name: ");
    scanf("%s", members[*memberCount].name);
    
    printf("Member added successfully!\n\n");
    (*memberCount)++;
}

// Function to display all members in the library
void displayMembers(struct Member members[], int memberCount) {
    if (memberCount == 0) {
        printf("No members registered.\n\n");
        return;
    }

    printf("Member ID\tName\n");
    printf("-------------------------\n");
    
    for (int i = 0; i < memberCount; i++) {
        printf("%d\t\t%s\n", members[i].id, members[i].name);
    }
    printf("\n");
}

int main() {
    struct Book books[100];
    struct Member members[100];
    int bookCount = 0;
    int memberCount = 0;
    int choice;
    
    while (1) {
        printf("Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book\n");
        printf("6. Add Member\n");
        printf("7. Display Members\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                borrowBook(books, bookCount);
                break;
            case 4:
                returnBook(books, bookCount);
                break;
            case 5:
                searchBook(books, bookCount);
                break;
            case 6:
                addMember(members, &memberCount);
                break;
            case 7:
                displayMembers(members, memberCount);
                break;
            case 8:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }
    return 0;
}
