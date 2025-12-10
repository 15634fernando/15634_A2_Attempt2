#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    Book();
    Book(string t, string a, string i, bool av, string date);

    string getTitle() const;
    string getIsbn() const;
    bool isAvailable() const;

    void print() const;
    void borrowBook();
};

// Sorting and helper functions used in testing
void sortByTitle(Book arr[], int size);
void printArray(const string& label, Book arr[], int size);
Book* findBookByIsbn(Book arr[], int size, const string& isbn);

#endif // BOOK_H
