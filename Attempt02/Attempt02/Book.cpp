#include "Book.h"

// ===== Book constructors =====
Book::Book() {
}

Book::Book(string t, string a, string i, bool av, string date)
    : title(t), author(a), isbn(i), available(av), dateAdded(date) {
}

// ===== Getters =====
string Book::getTitle() const {
    return title;
}

string Book::getIsbn() const {
    return isbn;
}

bool Book::isAvailable() const {
    return available;
}

// ===== Book methods =====
void Book::print() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Available: " << (available ? "Available" : "Not available") << endl;
    cout << "DateAdded: " << dateAdded << endl;
}

void Book::borrowBook() {
    if (available) {
        available = false;
        cout << "You borrowed \"" << title << "\"." << endl;
    } else {
        cout << "Sorry, \"" << title << "\" is not available." << endl;
    }
}

// ===== Free functions for sorting and test support =====
void sortByTitle(Book arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j].getTitle() > arr[j + 1].getTitle()) {
                Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(const string& label, Book arr[], int size) {
    cout << "\n" << label << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        arr[i].print();
        cout << endl;
    }
}

Book* findBookByIsbn(Book arr[], int size, const string& isbn) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getIsbn() == isbn) {
            return &arr[i];
        }
    }
    return nullptr;
}
