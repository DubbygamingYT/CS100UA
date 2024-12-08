/*
1.Define a Book structure to store information about a book, including:
title (dynamically allocated string).
author (dynamically allocated string).
id (integer for book ID).

2. Implement the following:
A shallow copy function for Book.
A deep copy function for Book.
Functions to create and display book details.

3. Allow the user to:
Add a book record.
Create a shallow copy of a book and modify it.
Create a deep copy of a book and modify it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book{
    char *title;
    char *author;
    int id;
}Book;

//Create Book Function
Book createBook(const char *title, const char *author, int id){
    Book newBook;
    newBook.title = malloc(strlen(title)+1);//allocate memory for title
    newBook.author = malloc(strlen(author)+1);//allocate memory for author
    if(newBook.title == NULL){
        printf("Memory Allocation Failed for Title!\n");
        free(newBook.title); //free the memory allocation
        exit(1);
    }
    if(newBook.author == NULL){ //checks for any undefined errors
        printf("Memory Allocation Failed for Author!\n");
        free(newBook.author);//free the memory allocation
        exit(1);
    }
    strcpy(newBook.title, title);
    strcpy(newBook.author,author);
    newBook.id = id;
    return newBook;
}

//Deep Copy Function
Book deepCopy(Book original){
    Book copy;
    copy.title = malloc(strlen(original.title)+1);//allocate new memory for title
    copy.author = malloc(strlen(original.author)+1);//allocate new memory for author
    if(copy.title == NULL){
        printf("Memory allocation failed in deep copy title!\n");
        free(copy.title);//prevent memory leaks
        exit(1);
    }
    if(copy.author == NULL){
        printf("Memory allocation failed in deep copy author!\n");
        free(copy.author);//prevent memory leaks
        exit(1);
    }
    //copy data from original book to copy
    strcpy(copy.title, original.title);
    strcpy(copy.author, original.author);
    copy.id = original.id;
    return copy;

}
//Display Book Function
void displayBook(Book book){
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Book ID: %d\n", book.id);
    printf("\n");
}
//Free Book Memory Function
void freeBook(Book *book){
    free(book->author);
    free(book->title);
}
//Main Function
int main(){
    //create an original book
    Book book1 = createBook("Pokemon Adventures", "Hidenori Kusaka", 0001);
    printf("Original Book:\n");
    displayBook(book1);

    //shallow copy of original book
    Book book2 = book1;
    //modify shallow copy
    strcpy(book2.title, "Rayquaza");
    strcpy(book2.author, "Pokemon");
    book2.id = 0002;
    printf("Modified Shallow Copy of Book:\n");
    displayBook(book2);
    printf("Do you want to see the Original Book after Shallow Copy? (y/n)\n");
    char answer[3];
    if (scanf("%2s", answer)) { // Limit input to 2 characters to avoid buffer overflow
    if (answer[0] == 'y' || answer[0] == 'Y') { // Check if the first character is 'y' or 'Y'
        printf("Original Book after Shallow Copy:\n");
        displayBook(book1);
    } else if (answer[0] == 'n' || answer[0] == 'N') {
        // Do nothing
        printf("\n");
    } else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}
    
    //deep copy of original book
    Book book3 = deepCopy(book1);
    //modify deep copy
    strcpy(book3.title, "Valorant");
    strcpy(book3.author, "Riot Games");
    book3.id = 0003;
    printf("Modified Deep Copy of Book:\n");
    displayBook(book3);
    printf("Do you want to see the Original Book after Deep Copy? (y/n)\n");
    char answer1[3];
    if (scanf("%2s", answer1)) { // Limit input to 2 characters to avoid buffer overflow
    if (answer1[0] == 'y' || answer1[0] == 'Y') { // Check if the first character is 'y' or 'Y'
        printf("\n");
        printf("Original Book after Deep Copy:\n");
        displayBook(book1);
    } else if (answer1[0] == 'n' || answer1[0] == 'N') {
        // Do nothing
        printf("\n");
    } else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}
   

    //free memory of the books except 2
    freeBook(&book1);
    freeBook(&book3);


    return 0;
}